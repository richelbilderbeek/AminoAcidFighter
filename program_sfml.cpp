#include "program_sfml.h"

#include <cassert>
#include <SFML/System.hpp>

#include "game_sfml.h"
#include "helper.h"

const int window_size = 600;

program_sfml::program_sfml(int argc, char * argv[])
  : m_do_play_music{argc == 1},
    m_do_profile_run{false},
    m_window{
      sf::VideoMode(window_size, window_size),
      "AminoAcidFighter",
      sf::Style::Titlebar | sf::Style::Close
    }
{
  assert(m_window.getSize().x == m_window.getSize().y);

  //constructor
  create_resources();

  m_window.setFramerateLimit(60);


  if (argc == 2 && std::string(argv[1]) == "--profile")
  {
    m_do_profile_run = true;
  }
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

void program_sfml::run_normal()
{
  //run member function
  ::run(
    m_window,
    m_window.getSize().x,
    m_do_play_music,
    m_sprites
  );
}

void program_sfml::run_profile()
{
  ::run_profile(
    m_window,
    m_window.getSize().x,
    m_sprites
  );
}
