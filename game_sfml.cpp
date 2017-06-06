#include "game_sfml.h"

#include "bullet_sfml.h"
#include "choose_amino_acids_menu_sfml.h"
#include "choose_n_players_menu_sfml.h"
#include "game.h"
#include "menu_sfml.h"
#include "player_sfml.h"

game_sfml::game_sfml(sf::RenderWindow& window,
  const bool do_play_music,
  std::vector<amino_acid> amino_acids,
  const bool is_profile_run,
  Sprites_sfml& sprites
) : m_do_play_music{do_play_music},
    m_game{game(amino_acids, 600)},
    m_hit_ranges{set_hit_ranges(
      create_players(amino_acids, window.getSize().x),get_start_positions())},
    m_is_profile_run{is_profile_run},
    m_life_bars{set_life_bars(amino_acids.size(), get_life_bar_positions())},
    m_sprites(sprites),
    m_state{program_state::battle},
    m_window{window}
{
}

game_sfml::~game_sfml()
{
  m_music.stop();
}

void game_sfml::resize_life_bars()
{
  const auto players = get_players(*this);
  //Show the players' HPs in the bars
  for(auto i = 0u; i < players.size(); ++i)
  {
    m_life_bars[i].setSize(sf::Vector2f(players[i].get_hp(), m_life_bars[i].getSize().y));
  }
}

std::vector<double> collect_hit_points(const game_sfml& g)
{
  return collect_hit_points(g.get_game());
  /*
  std::vector<double> hps;
  for (const auto& p: get_players())
  {
    hps.push_back(p.get_hp());
  }
  return hps;
  */
}

void game_sfml::display()
{
  // 600 fps (current speed on Travis) for 60 seconds
  const int kill_frame{m_is_profile_run ? 600 * 60: -1};
  static int frame = 0;

  //Kill in profiling
  ++frame;
  if (kill_frame > 0 && frame > kill_frame)
  {
    m_window.close();
    m_state = program_state::quit;
    return;
  }

  m_window.clear();
  m_window.draw(m_sprites.get_background());
  draw_game_components(m_window, m_life_bars, m_hit_ranges, get_bullets(*this));
  draw_players(get_players(*this), m_window, m_sprites);
  m_window.display();
}

void draw_game_components(
  sf::RenderWindow &w,
  std::vector<sf::RectangleShape> life_bars,
  std::vector<sf::CircleShape> hit_ranges,
  std::vector<bullet> bullets)
{
  for(auto i{0u}; i != life_bars.size(); ++i) {
    if(life_bars[i].getSize().x > 0.0) {
      draw_life_bar(life_bars[i], w);
    }
  }
  for(auto i{0u}; i != hit_ranges.size(); ++i) {
    if(life_bars[i].getSize().x > 0.0) {
      draw_hit_ranges(hit_ranges[i], w);
    }
  }
  for(auto& bullet : bullets) {
    const int window_size = w.getSize().x;
    //Must we draw the 'shadow' player left or right?
    const bool must_right{bullet.get_x() < window_size / 2};
    const int dx = must_right ? window_size : -window_size;
    const bool must_down{bullet.get_y() < window_size / 2};
    const int dy = must_down ? window_size : -window_size;
    //Real position
    w.draw(to_sprite(bullet));
    //Horizontal of player
    bullet.set_position(bullet.get_x() + dx, bullet.get_y());
    w.draw(to_sprite(bullet));
    //Down-Right of player
    bullet.set_position(bullet.get_x(), bullet.get_y() +  dy);
    w.draw(to_sprite(bullet));
    //Below player
    bullet.set_position(bullet.get_x() - dx, bullet.get_y());
    w.draw(to_sprite(bullet));
  }
}

void game_sfml::execute()
{
  assert(m_state == program_state::battle);
  while(m_window.isOpen())
  {
    tick();
    //Quit
    if (m_state == program_state::quit) return;
    //Next screen
    if (m_state == program_state::winner) return;
    //Stay here
    assert(m_state == program_state::battle);
  }
}

const std::vector<bullet>& get_bullets(const game_sfml& g)
{
  return get_bullets(g.get_game());
}

std::vector<bullet>& get_bullets(game_sfml& g)
{
  return get_bullets(g.get_game());
}

std::vector<sf::Vector2f> get_life_bar_positions()
{
    const std::vector<sf::Vector2f> life_bar_positions {
      sf::Vector2f(10 , 10 ),
      sf::Vector2f(490, 10 ),
      sf::Vector2f(10 , 580),
      sf::Vector2f(490, 580)
  };
  return life_bar_positions;
}

const std::vector<player>& get_players(const game_sfml& g)
{
  return get_players(g.get_game());
}

std::vector<player>& get_players(game_sfml& g)
{
  return get_players(g.get_game());
}

std::vector<sf::Vector2f> get_start_positions()
{
  const std::vector<sf::Vector2f> start_positions {
      sf::Vector2f(175, 175),
      sf::Vector2f(425, 175),
      sf::Vector2f(175, 425),
      sf::Vector2f(425, 425)
  };
  return start_positions;
}

int get_winner(const game_sfml& g)
{
  //Count the number of players that live
  const std::vector<double> hps = collect_hit_points(g);
  const int n_alive = std::count_if(
    std::begin(hps), std::end(hps),
    [](const double hp) { return hp > 0.0; }
  );

  //At least two players live
  if (n_alive > 1) return 0;

  //We have a winner or everyone died
  const int n_players = hps.size();
  for (int i=0; i!=n_players; ++i)
  {
    if (hps[i] > 0.0) { return i + 1; }
  }
  //Everyone, or the last two players, died at the same time
  return -1;
}

void game_sfml::process_event(sf::Event event)
{
  switch(event.type)
  {
    case sf::Event::Closed:
      m_state = program_state::quit;
      m_window.close();
      break;
    case sf::Event::KeyPressed:
      // keyboard support for player1 and player2
      assert(get_players(*this).size() >= 1);
      respond_to_key(
        get_players(*this)[0],
        get_players(*this)[1],
        get_bullets(*this),
        m_game
      );
      break;
    case sf::Event::JoystickButtonPressed:
      // joystick support for player3 and player4
      respond_to_joystick(
        get_players(*this)[2],
        get_players(*this)[3],
        get_bullets(*this));
      break;
    default:
      break;
  }
}

std::vector<sf::CircleShape> set_hit_ranges(
  std::vector<player> ps,
  std::vector<sf::Vector2f> start_positions
)
{
  std::vector<sf::CircleShape> hit_ranges;
  for(auto i{0u}; i != ps.size(); ++i)
  {
    const float hit_range_size = get_hit_range_size();
    sf::CircleShape hit_range;
    hit_range.setPosition(start_positions[i]);
    hit_range.setRadius(hit_range_size);
    hit_range.setOrigin(sf::Vector2f(hit_range_size, hit_range_size));
    hit_range.setOutlineColor(sf::Color::Blue);
    hit_range.setOutlineThickness(2.0);
    hit_range.setFillColor(sf::Color::Transparent);
    hit_ranges.push_back(hit_range);
  }
  return hit_ranges;
}

std::vector<sf::RectangleShape> set_life_bars(
  int player_amount,
  std::vector<sf::Vector2f> life_bar_positions)
{
  std::vector<sf::RectangleShape> life_bars;
  for(auto i{0}; i != player_amount; ++i) {
    sf::RectangleShape life_bar;
    life_bar.setPosition(life_bar_positions[i]);
    life_bar.setSize(sf::Vector2f(100, 10));
    life_bar.setFillColor(sf::Color::Red);
    life_bars.push_back(life_bar);
  }
  return life_bars;
}

void game_sfml::tick()
{
  m_game.tick();
  assert(m_window.isOpen());
  sf::Event event;
  while(m_window.pollEvent(event))
  {
    process_event(event);
  }
  display();

  assert(m_window.getSize().x == m_window.getSize().y);

  //Move hit ranges
  for(auto i = 0u; i != get_players(*this).size(); ++i)
  {
    m_hit_ranges[i].setPosition(get_players(*this)[i].get_x() + get_players(*this)[i].get_speed_x(),
                              get_players(*this)[i].get_y() + get_players(*this)[i].get_speed_y());
  }

  //Check if bullet hits player
  resize_life_bars();

  //Look for winner
  if(get_winner(*this) != 0)
  {
    m_state = program_state::winner;
  }
}

