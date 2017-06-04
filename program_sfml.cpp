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
    m_sprites{},
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
  game_sfml m(
    m_window,
    do_play_music(m_args),
    m_amino_acids,
    is_profile_run(m_args),
    m_sprites
  );

  assert(m.get_state() == program_state::battle);
  m.execute();

  m_state = m.get_state();
  if(m_state == program_state::quit) return;
  assert(m_state == program_state::winner);

  /*
  if(sf::Joystick::isConnected(0)) {
      std::cout << "controller connected" << '\n';
  }
  */
}

void program_sfml::run_choose_amino_acids_menu()
{
  choose_amino_acids_menu_sfml m(
    m_window,
    m_sprites,
    do_play_music(m_args),
    m_amino_acids
  );
  m.execute();

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
