#ifndef WINNER_SCREEN_SFML_H
#define WINNER_SCREEN_SFML_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include "winner_screen.h"
#include "program_state.h"

class winner_screen_sfml
{
public:
  winner_screen_sfml(
    sf::RenderWindow& w,
    const bool do_play_music = true);

  ///Get the current state of the program
  program_state get_state() const noexcept { return m_state; }

  void execute();

  void process_event(const sf::Event& event);

private:
  ///Will music be played?
  bool m_do_play_music;

  ///The logic behind this menu
  winner_screen m_menu;

  ///Music played, starts at constructor, ends at destructor
  sf::Music m_music;

  ///The current state of the program
  program_state m_state;

  ///Window used for displayal
  sf::RenderWindow& m_window;

  ///Text of which player has won
  sf::Text m_winner_text;

  ///Show this menu on the screen
  void display();
};

sf::Text create_winner_text(const int winner);

#endif // WINNER_SCREEN_SFML_H
