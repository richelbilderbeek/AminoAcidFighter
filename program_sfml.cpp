#include "program_sfml.h"

#include <cassert>
#include <SFML/System.hpp>

#include "choose_amino_acids_menu_sfml.h"
#include "choose_n_players_menu_sfml.h"
#include "game.h"
#include "game_sfml.h"
#include "helper.h"
#include "program.h"

program_sfml::program_sfml(const std::vector<std::string>& args)
  : m_amino_acids{create_amino_acids(args)},
    m_args{args},
    m_state{create_state(args)},
    m_window{
      sf::VideoMode(600, 600), //Window is 600 x 600 pixels
      "AminoAcidFighter",
      sf::Style::Titlebar | sf::Style::Close
    }
{
  if (is_help(args))
  {
    show_help();
  }

  //Create all resources needed: pictures, sounds, etcetera
  create_resources();

  m_window.setFramerateLimit(60);
}

program_sfml::~program_sfml()
{
  //destructor
  m_window.close();
}



void program_sfml::run()
{
  while(m_window.isOpen())
  {
    //This should one day evolve to the State Design Pattern
    switch(m_state)
    {
      case program_state::choose_n_players: run_choose_n_player_menu(); break;
      case program_state::select_players: run_choose_amino_acids_menu(); break;
      case program_state::battle: run_battle(); break;
      case program_state::winner: run_winner_screen(); break;
      case program_state::quit: return;
    }
  }
}

void program_sfml::run_battle()
{
  assert(m_state == program_state::battle);

  assert(m_window.getSize().x == m_window.getSize().y);
  const int window_size = m_window.getSize().x;
  auto players = create_players(m_amino_acids, window_size);
  game_sfml m(m_window, do_play_music(m_args));

  assert(m.get_state() == program_state::battle);
  m.execute();

  m_state = m.get_state();
  if(m_state == program_state::quit) return;
  assert(m_state == program_state::winner);

  /*
  assert(m_window.getSize().x == m_window.getSize().y);
  const int window_size = m_window.getSize().x;
  auto players = create_players(m_amino_acids, window_size);
  // 6 fps (current speed on Travis) for 5 minutes
  const int kill_frame{is_profile_run(m_args) ? 300 : -1};
  static int frame = 0;
  const std::vector<sf::Vector2f> start_positions = get_start_positions();
  const std::array<sf::Vector2f, 4> life_bar_positions = get_life_bar_positions();
  std::vector<sf::RectangleShape> life_bars = set_life_bars(players.size(), life_bar_positions);
  std::vector<sf::CircleShape> hit_ranges = set_hit_ranges(players, start_positions);
  std::vector<bullet> bullets;

  if(sf::Joystick::isConnected(0)) {
      std::cout << "controller connected" << '\n';
  }

  while(m_window.isOpen()) {
    //Kill in profiling
    ++frame;
    if (kill_frame > 0 && frame > kill_frame)
    {
      m_window.close();
      return;
    }

    sf::Event event;
    while(m_window.pollEvent(event)) {
      process_event_game(
        event,
        m_window,
        players,
        bullets,
        window_size
      );
    }

    //Move players, hit range and bullets
    for(auto i = 0u; i != players.size(); ++i) { players[i].move(window_size); }
    for(auto& bullet : bullets) {
      bullet.slow_down();
      bullet.move(window_size);
    }
    for(auto i = 0u; i != players.size(); ++i)
    {
      hit_ranges[i].setPosition(players[i].get_x() + players[i].get_speed_x(),
                                players[i].get_y() + players[i].get_speed_y());
    }
    //Check if bullet hits player
    bullet_hits_player(bullets, players, life_bars);

    //Remove all bullets that have no speed
    remove_slow_bullets(bullets);

    m_window.clear(sf::Color(128,128,128));
    draw_game_components(m_window, life_bars, hit_ranges, bullets);
    draw_players(players, m_window, m_sprites);
    m_window.display();
  }
  */
}

void program_sfml::run_choose_amino_acids_menu()
{
  choose_amino_acids_menu_sfml m(m_window, do_play_music(m_args), m_amino_acids);
  m.execute(m_sprites);

  m_state = m.get_state();
  if(m_state == program_state::quit) return;
  assert(m_state == program_state::battle);
  m_amino_acids = m.get_amino_acids();
}

void program_sfml::run_choose_n_player_menu()
{
  const int n_players = m_amino_acids.size();
  choose_n_players_menu_sfml m(m_window, do_play_music(m_args), n_players);
  m.execute();
  m_state = m.get_state();
  if(m_state == program_state::quit) return;
  assert(m_state == program_state::select_players);
  m_amino_acids.resize(m.get_n_players());
}

void program_sfml::run_winner_screen()
{

}
