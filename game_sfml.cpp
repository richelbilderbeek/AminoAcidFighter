#include "game_sfml.h"
#include "game.h"
#include "player_sfml.h"
#include "bullet_sfml.h"
#include "menu_sfml.h"

void bullet_hits_player(
  std::vector<bullet> bullets,
  std::vector<player> &players,
  std::vector<sf::RectangleShape> &life_bars)
{
  for(auto i = 0u; i < players.size(); ++i) {
    for(auto j = 0u; j < bullets.size(); ++j) {
      float distance = calculate_distance_bullet_player(bullets[j], players[i]);
      if(distance <= get_hit_range_size()) {
        players[i].lose_hp();
        //TODO remove_bullets_that_hits();
      }
    }
  }
  //Show the players' HPs in the bars
  for(auto i = 0u; i < players.size(); ++i) {
    life_bars[i].setSize(sf::Vector2f(players[i].get_hp(), life_bars[i].getSize().y));
  }
}

std::vector<player> create_game_players(
  std::vector<amino_acid> amino_acids,
  std::vector<sf::Vector2f> player_positions)
{
  std::vector<player> players;
  const int n_players = amino_acids.size();
  for (int i{0}; i!=n_players; ++i)
  {
    players.push_back(
      player(
        amino_acids[i],
        player_positions[i].x,
        player_positions[i].y
      )
    );
  }
  return players;
}

void draw_game(
  sf::RenderWindow &window,
  std::vector<sf::RectangleShape> life_bars,
  std::vector<sf::CircleShape> hit_ranges,
  std::vector<bullet> bullets)
{
  for(auto i{0u}; i != life_bars.size(); ++i) {
    if(life_bars[i].getSize().x > 0.0) {
      draw_life_bar(life_bars[i], window);
    }
  }
  for(auto i{0u}; i != hit_ranges.size(); ++i) {
    if(life_bars[i].getSize().x > 0.0) {
      draw_hit_ranges(hit_ranges[i], window);
    }
  }
  for(auto& bullet : bullets) {
    const int window_size = window.getSize().x;
    //Must we draw the 'shadow' player left or right?
    const bool must_right{bullet.get_x() < window_size / 2};
    const int dx = must_right ? window_size : -window_size;
    const bool must_down{bullet.get_y() < window_size / 2};
    const int dy = must_down ? window_size : -window_size;
    //Real position
    window.draw(to_sprite(bullet));
    //Horizontal of player
    bullet.set_position(bullet.get_x() + dx, bullet.get_y());
    window.draw(to_sprite(bullet));
    //Down-Right of player
    bullet.set_position(bullet.get_x(), bullet.get_y() +  dy);
    window.draw(to_sprite(bullet));
    //Below player
    bullet.set_position(bullet.get_x() - dx, bullet.get_y());
    window.draw(to_sprite(bullet));
  }
}

void play_game(
  sf::RenderWindow &window,
  const int window_size,
  std::vector<player> players
)
{
  const std::vector<sf::Vector2f> start_positions = get_start_positions();
  const std::array<sf::Vector2f, 4> life_bar_positions = get_life_bar_positions();
  std::vector<sf::RectangleShape> life_bars = set_life_bars(players.size(), life_bar_positions);
  std::vector<sf::CircleShape> hit_ranges = set_hit_ranges(players, start_positions);
  std::vector<bullet> bullets;

  if(sf::Joystick::isConnected(0)) {
      std::cout << "controller connected" << '\n';
  }

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      process_event_game(
        event,
        window,
        players,
        bullets,
        window_size);
    }

    //Move players, hit range and bullets
    for(auto i = 0u; i != players.size(); ++i) { players[i].move(window_size); }
    for(auto& bullet : bullets) { bullet.move(window_size); }
    for(auto i = 0u; i != players.size(); ++i) {
      hit_ranges[i].setPosition(players[i].get_x() + players[i].get_speed_x(),
                                players[i].get_y() + players[i].get_speed_y());
    }
    //Check if bullet hits player
    bullet_hits_player(bullets, players, life_bars);

    //Remove all bullets that are out of the screen
    //remove_out_of_screen_bullets(
    //bullets,
    //window_size);

    window.clear(sf::Color(128,128,128));
    draw_game(window, life_bars, hit_ranges, bullets);
    draw_players(players, window);
    window.display();
  }
}

void process_event_game(
  sf::Event event,
  sf::RenderWindow &window,
  std::vector<player> &players,
  std::vector<bullet> &bullets,
  const int /* window_size */)
{
  switch(event.type) {
    case sf::Event::Closed:
      window.close();
      break;
    case sf::Event::KeyPressed:
      // keyboard support for player1 and player2
      respond_to_key(
        players[0],
        players[1],
        bullets/*,
        window_size*/);
      break;
    case sf::Event::JoystickButtonPressed:
      // joystick support for player3 and player4
      respond_to_joystick(
        players[2],
        players[3],
        bullets/*,
        window_size*/);
      break;
    default:
      break;
  }
}

void run(
  sf::RenderWindow &window,
  const int window_size,
  const bool do_play_music)
{
  program_state state{program_state::choose_n_players};
  std::vector<amino_acid> amino_acids = { amino_acid::alanine, amino_acid::alanine};
  std::vector<player> players;

  while(window.isOpen()) {
    switch(state) {
      case program_state::choose_n_players: {
        const int new_size = choose_n_players(
          window,
          do_play_music,
          amino_acids.size());
        if (new_size < 1) return;
        state = program_state::select_players;
        amino_acids.resize(new_size); //May result in undefined behavior if size is increased
      }
      break;
      case program_state::select_players: {
        players = choose_aminoacids(
          window,
          amino_acids);
        if (amino_acids.empty()) return; //Quit
        state = program_state::battle;
      }
      break;
      case program_state::battle:
        play_game(
          window,
          window_size,
          players);
        assert(!"something should happen now, e.g. a winner screen"); //!OCLINT need to add more screens
      break;
      case program_state::quit:
        return;
      default: assert(!"TODO");
    }
  }
}

std::vector<sf::CircleShape> set_hit_ranges(
  std::vector<player> players,
  std::vector<sf::Vector2f> start_positions)
{
  std::vector<sf::CircleShape> hit_ranges;
  for(auto i{0u}; i != players.size(); ++i)
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
  std::array<sf::Vector2f, 4> life_bar_positions)
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

std::array<sf::Vector2f, 4> get_life_bar_positions()
{
    const std::array<sf::Vector2f, 4> life_bar_positions {
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
