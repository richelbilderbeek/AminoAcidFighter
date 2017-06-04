#include "game_sfml.h"
#include "game.h"
#include "player_sfml.h"
#include "bullet_sfml.h"
#include "menu_sfml.h"
#include "choose_n_players_menu_sfml.h"
#include "choose_amino_acids_menu_sfml.h"

game_sfml::game_sfml(sf::RenderWindow& window,
  const bool do_play_music,
  std::vector<amino_acid> amino_acids,
  const bool is_profile_run
) : m_do_play_music{do_play_music},
    m_hit_ranges{set_hit_ranges(create_players(amino_acids, window.getSize().x),get_start_positions())},
    m_is_profile_run{is_profile_run},
    m_life_bars{set_life_bars(amino_acids.size(), get_life_bar_positions())},
    m_players{create_players(amino_acids, window.getSize().x)},
    m_state{program_state::battle},
    m_window{window}
{

}

game_sfml::~game_sfml()
{
  m_music.stop();
}

void game_sfml::bullet_hits_player()
{
  for(auto i = 0u; i < m_players.size(); ++i) {
    for(auto j = 0u; j < m_bullets.size(); ++j) {
      float distance = calculate_distance_bullet_player(m_bullets[j], m_players[i]);
      if(distance <= get_hit_range_size()) {
        m_players[i].lose_hp();
        m_bullets[j].slow_down();
      }
    }
  }
  //Show the players' HPs in the bars
  for(auto i = 0u; i < m_players.size(); ++i) {
    m_life_bars[i].setSize(sf::Vector2f(m_players[i].get_hp(), m_life_bars[i].getSize().y));
  }
}

void game_sfml::display(Sprites_sfml &sprites)
{
  // 60 fps (current speed on Travis) for 5 minutes
  const int kill_frame{m_is_profile_run ? 60 * 5 * 50: -1};
  static int frame = 0;

  //Kill in profiling
  ++frame;
  if (kill_frame > 0 && frame > kill_frame)
  {
    m_window.close();
    m_state = program_state::quit;
    return;
  }

  m_window.clear(sf::Color(128,128,128));
  draw_game_components(m_window, m_life_bars, m_hit_ranges, m_bullets);
  draw_players(m_players, m_window, sprites);
  m_window.display();
}

void game_sfml::execute(Sprites_sfml &sprites)
{
  assert(m_state == program_state::battle);
  while (1) {
    tick(sprites);
    //Quit
    if (m_state == program_state::quit) return;
    //Next screen
    if (m_state == program_state::winner) return;
    //Stay here
    assert(m_state == program_state::battle);
  }
}

void game_sfml::process_event(
  sf::Event event,
  std::vector<bullet> &bullets
)
{
  switch(event.type)
  {
    case sf::Event::Closed:
      m_window.close();
      break;
    case sf::Event::KeyPressed:
      // keyboard support for player1 and player2
      assert(m_players.size() >= 1);
      respond_to_key(
        m_players[0],
        m_players[1],
        bullets);
      break;
    case sf::Event::JoystickButtonPressed:
      // joystick support for player3 and player4
      respond_to_joystick(
        m_players[2],
        m_players[3],
        bullets);
      break;
    default:
      break;
  }
}

void game_sfml::tick(Sprites_sfml &sprites)
{
  while(m_window.isOpen())
  {
    sf::Event event;
    while(m_window.pollEvent(event)) {
      process_event(
        event,
        m_bullets
      );
    }

    display(sprites);

    //Move players, hit range and bullets
    assert(m_window.getSize().x == m_window.getSize().y);
    for(auto i = 0u; i != m_players.size(); ++i) { m_players[i].move(m_window.getSize().x); }
    for(auto& bullet : m_bullets) {
      bullet.slow_down();
      bullet.move(m_window.getSize().x);
    }
    for(auto i = 0u; i != m_players.size(); ++i)
    {
      m_hit_ranges[i].setPosition(m_players[i].get_x() + m_players[i].get_speed_x(),
                                m_players[i].get_y() + m_players[i].get_speed_y());
    }
    //Check if bullet hits player
    bullet_hits_player();

    //Remove all bullets that have no speed
    remove_slow_bullets(m_bullets);
  }
}





std::vector<player> create_game_players(
  std::vector<amino_acid> aas,
  std::vector<sf::Vector2f> ps_pos)
{
  std::vector<player> players;
  const int n_players = aas.size();
  for (int i{0}; i!=n_players; ++i)
  {
    players.push_back(
      player(
        aas[i],
        ps_pos[i].x,
        ps_pos[i].y
      )
    );
  }
  return players;
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

program_state run_winner_screen(
  sf::RenderWindow &w,
  bool do_play_music,
  std::vector<sf::RectangleShape> life_bars)
{
  const sf::Text winner_text = create_winner_text(life_bars);
  winner_screen_sfml m(w, do_play_music);
  m.execute(winner_text);
  const program_state state = m.get_state();
  if(state == program_state::quit) return state;
  assert(state == program_state::winner);
  return state;
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

