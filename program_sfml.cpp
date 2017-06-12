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

  //Might not be needed with some computers
  if(!is_profile_run(args))
  {
    m_window.setFramerateLimit(60);
  }
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

  game g(m_amino_acids, 600, do_play_music(m_args), is_profile_run(m_args));

  game_sfml m(
    m_window,
    g,
    m_sprites
  );

  m.execute();

  //Read the new state from the dialog
  m_state = get_state(m);
  if(m_state == program_state::quit) return;
  assert(m_state == program_state::winner);
  m_winner = get_winner(m);
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

  //Read the new state from the dialog
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

  //Read the new state from the dialog
  m_state = m.get_state();
  if(m_state == program_state::quit) return;
  assert(m_state == program_state::select_players);
  m_amino_acids.resize(m.get_n_players());
}

void program_sfml::run_winner_screen()
{
  winner_screen_sfml m(m_window, m_winner, do_play_music(m_args));
  m.execute();

  //Read the new state from the dialog
  m_state = m.get_state();
  if(m_state == program_state::quit) return;
  assert(m_state == program_state::choose_n_players);
}
