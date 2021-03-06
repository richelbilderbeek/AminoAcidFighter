#ifndef CHOOSE_N_PLAYERS_MENU_SFML_H
#define CHOOSE_N_PLAYERS_MENU_SFML_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "choose_n_players_menu.h"
#include "program_state.h"

/// SFML visualization of the choose_n_players_menu
class choose_n_players_menu_sfml
{
public:
  ///Starts the music
  ///@param n_players the initial number of players suggested
  choose_n_players_menu_sfml(
    sf::RenderWindow& window,
    const bool do_play_music = true,
    const int n_players = 2
  );

  ///Stops the music
  ~choose_n_players_menu_sfml();

  ///Will the music be player
  bool do_play_music() const noexcept { return m_do_play_music; }

  ///Runs this menu, which is handling input and displayal.
  ///Closes when the user wants to quit
  ///or continue to the next menu screen
  ///This can be obtained with the do_quit member function
  void execute();

  ///Get the current number of players chosen
  int get_n_players() const noexcept { return m_menu.get_n_player(); }

  ///Obtain the current or state after execute
  program_state get_state() const noexcept { return m_state; }

  ///Handle input and show this screen once, to be used in testing only
  void tick();

private:

  ///Will music be played?
  bool m_do_play_music;

  ///The font for all texts
  sf::Font m_font;

  ///The lower text
  sf::Text m_lower_text;

  ///The logic behind this menu
  choose_n_players_menu m_menu;

  ///Music played, starts at constructor, ends at destructor
  sf::Music m_music;

  ///In which state is the program while and directly after this menu?
  program_state m_state;

  ///The upper text
  sf::Text m_top_text;

  ///Window used for displayal
  sf::RenderWindow& m_window;

  ///Show this menu on the screen
  void display();

  ///Process a single event
  void process_event(const sf::Event& event);
};

///Get the display color of the text showing the number of players
sf::Color n_players_to_color(const int player_amount);

#endif // CHOOSE_N_PLAYERS_MENU_SFML_H
