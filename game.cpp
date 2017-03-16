#include "game.h"


void draw_game(
  sf::RenderWindow &window,
  std::vector<sf::RectangleShape> life_bars,
  std::vector<sf::CircleShape> hit_ranges,
  std::vector<player> players,
  std::vector<bullet> bullets)
{
  for(auto i{0u}; i != life_bars.size(); ++i) { draw_life_bar(life_bars[i], window); }
  for(auto i{0u}; i != hit_ranges.size(); ++i) { draw_hit_ranges(hit_ranges[i], window); }
  for(auto i{0u}; i != players.size(); ++i) { draw(players[i], window); }
  for(auto& bullet : bullets) { window.draw(bullet.get_sprite()); }
}

void play_game(
  sf::RenderWindow &window,
  const int window_size,
  const std::vector<amino_acid>& amino_acids
)
{
  const std::vector<sf::Vector2f> start_positions = set_start_positions();
  std::vector<player> players = set_players(amino_acids, start_positions);
  const std::array<sf::Vector2f, 4> life_bar_positions = set_life_bar_positions();
  std::vector<sf::RectangleShape> life_bars = set_life_bars(amino_acids, life_bar_positions);
  std::vector<sf::CircleShape> hit_ranges = set_hit_ranges(amino_acids, start_positions);
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
    for(auto& bullet : bullets) { bullet.move(); }
    for(auto i = 0u; i != players.size(); ++i) {
      hit_ranges[i].setPosition(players[i].get_position() + players[i].get_speed());
    }

    //Check if bullet hits player
    const float hit_range_size{25.0};
    for(auto i = 0u; i < players.size(); ++i)
    {
      for(auto j = 0u; j < bullets.size(); ++j)
      {
        float distance = calculate_distance_bullet_player(bullets[j], players[i]);
        std::cout << distance << std::endl;
        if(distance <= hit_range_size)
        {
          auto new_x = life_bars[i].getSize().x - 5;
          auto new_y = life_bars[i].getSize().y;
          life_bars[i].setSize(sf::Vector2f(new_x, new_y));
        }
      }
    }

    //Remove all bullets that are out of the screen
    remove_bullets(
      bullets,
      window_size);

    window.clear(sf::Color(128,128,128));
    draw_game(window, life_bars, hit_ranges, players, bullets);
    window.display();
  }
}

void process_event_game(sf::Event event,
  sf::RenderWindow &window,
  std::vector<player> &players,
  std::vector<bullet> &bullets,
  const int window_size)
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
        bullets,
        window_size);
      break;
    case sf::Event::JoystickButtonPressed:
      // joystick support for player3 and player4
      respond_to_joystick(
        players[2],
        players[3],
        bullets,
        window_size);
      break;
    default:
      break;
  }
}

void run(
  sf::RenderWindow &window,
  const int window_size,
  const int argc)
{

  program_state state{program_state::choose_n_players};
  std::vector<amino_acid> players = { amino_acid::alanine, amino_acid::alanine};

  while(window.isOpen()) {
    switch(state) {
      case program_state::choose_n_players: {
        const int new_size = choose_n_players(
          window,
          argc,
          players.size());
        state = program_state::select_players;
        players.resize(new_size); //May result in undefined behavior if size is increased
      }
      break;
      case program_state::select_players: {
        players = choose_aminoacids(
          window,
          argc,
          players);
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
    }
  }
}

std::vector<sf::CircleShape> set_hit_ranges(
  std::vector<amino_acid> amino_acids,
  std::vector<sf::Vector2f> start_positions)
{
  std::vector<sf::CircleShape> hit_ranges;
  for(auto i{0u}; i != amino_acids.size(); ++i)
  {
    const float hit_range_size{25.0};
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
  std::vector<amino_acid> amino_acids,
  std::array<sf::Vector2f, 4> life_bar_positions)
{
  std::vector<sf::RectangleShape> life_bars;
  for(auto i{0u}; i != amino_acids.size(); ++i)
  {
    sf::RectangleShape life_bar;
    life_bar.setPosition(life_bar_positions[i]);
    life_bar.setSize(sf::Vector2f(100, 10));
    life_bar.setFillColor(sf::Color::Red);
    life_bars.push_back(life_bar);
  }
  return life_bars;
}

std::array<sf::Vector2f, 4> set_life_bar_positions()
{
    const std::array<sf::Vector2f, 4> life_bar_positions {
      sf::Vector2f(10 , 10 ),
      sf::Vector2f(490, 10 ),
      sf::Vector2f(10 , 580),
      sf::Vector2f(490, 580)
  };
  return life_bar_positions;
}

std::vector<sf::Vector2f> set_start_positions()
{
  const std::vector<sf::Vector2f> start_positions
  {
      sf::Vector2f(175, 175),
      sf::Vector2f(425, 175),
      sf::Vector2f(175, 425),
      sf::Vector2f(425, 425)
  };
  return start_positions;
}

std::vector<player> set_players(
  std::vector<amino_acid> amino_acids,
  std::vector<sf::Vector2f> player_positions)
{
  std::vector<player> players;
  const int n_amino_acids = amino_acids.size();

  for (int i{0}; i != n_amino_acids; ++i) {
    players.push_back(
      create_player(
        amino_acids[i],
        player_positions[i]));
  }
  return players;
}

/*void bullet_hits_player(
  std::vector<bullet> bullets,
  std::vector<player> players,
  std::vector<sf::RectangleShape> &life_bars)
{
  const float hit_range_size{25.0};
  for(auto i = 0u; i < players.size(); ++i)
  {
    for(auto j = 0u; j < bullets.size(); ++j)
    {
      float distance = calculate_distance_bullet_player(bullets[j], players[i]);
      std::cout << distance << std::endl;
      if(distance - hit_range_size <= 0)
      {
        life_bars[i].setSize(sf::Vector2f(50, 10));
      }
    }
  }
}*/

float calculate_distance_bullet_player(bullet bullets, player players)
{
  float bullet_position_x = bullets.get_position().x;
  float bullet_position_y = bullets.get_position().y;
  float player_position_x = players.get_position().x;
  float player_position_y = players.get_position().y;

  float length_x = bullet_position_x - player_position_x;
  float length_y = bullet_position_y - player_position_y;
  float x2 = length_x * length_x;
  float y2 = length_y * length_y;
  float er = x2 + y2;
  return sqrt(er);
}
