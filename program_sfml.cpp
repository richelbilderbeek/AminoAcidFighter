#include "program_sfml.h"

#include <cassert>
#include <SFML/System.hpp>

#include "game.h"
#include "game_sfml.h"
#include "helper.h"

const int window_size = 600;

program_sfml::program_sfml(int argc, char * argv[])
  : m_amino_acids{amino_acid::alanine, amino_acid::alanine},
    m_do_play_music{argc == 1},
    m_do_profile_run{argc == 2 && std::string(argv[1]) == "--profile"},
    m_state{program_state::choose_n_players},
    m_window{
      sf::VideoMode(window_size, window_size),
      "AminoAcidFighter",
      sf::Style::Titlebar | sf::Style::Close
    }
{
  assert(m_window.getSize().x == m_window.getSize().y);

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
  assert(m_window.getSize().x == m_window.getSize().y);
  //do profile run
  if (m_do_profile_run)
  {
    run_profile();
  }
  else
  {
    run_normal();
  }
}

void program_sfml::run_battle()
{
  display(
    m_window,
    window_size,
    m_amino_acids,
    m_sprites
  );
}

void program_sfml::run_choose_amino_acids_menu()
{
  m_state = ::run_choose_amino_acids_menu(
    m_window,
    m_do_play_music,
    m_amino_acids,
    m_sprites
  );
}

void program_sfml::run_choose_n_player_menu()
{
  m_state = ::run_choose_n_player_menu(
    m_window,
    m_do_play_music,
    m_amino_acids
  );
}

void program_sfml::run_normal()
{
  while(m_window.isOpen())
  {
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

void program_sfml::run_profile()
{
  const std::vector<amino_acid> aas =
  {
    amino_acid::alanine,
    amino_acid::glycine,
    amino_acid::tryptophan,
    amino_acid::valine
  };
  const auto ps = create_players(aas, window_size);
  const int kill_frame{6 * 300}; // 6 fps (current speed on Travis) for 5 minutes
  display(m_window, window_size, ps, m_sprites, kill_frame);
}

void program_sfml::run_winner_screen()
{

}
