#ifndef CHOOSE_AMINO_ACIDS_MENU_SFML_H
#define CHOOSE_AMINO_ACIDS_MENU_SFML_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "choose_amino_acids_menu.h"
#include "player.h"
#include "player_sfml.h"
#include "program.h"
#include "program_state.h"

/// SFML visualization of the choose_amino_acids_menu
class choose_amino_acids_menu_sfml
{
public:
  ///Starts the music
  choose_amino_acids_menu_sfml(
    sf::RenderWindow& window,
    Sprites_sfml& sprites,
    const bool do_play_music = true,
    const std::vector<amino_acid> initial_amino_acids
      = create_first_amino_acids()
  );

  ///Stops the music
  ~choose_amino_acids_menu_sfml();

  ///Runs this menu, which is handling input and displayal.
  ///Closes when the user wants to quit
  ///or continue to the game
  ///This can be obtained with the do_quit member function
  void execute();

  ///Get the current amino acids
  std::vector<amino_acid> get_amino_acids() const noexcept { return m_menu.get_amino_acids(); }

  ///Obtain the current or state after execute
  program_state get_state() const noexcept { return m_state; }

  ///Handle input and show this screen once, to be used in testing only
  void tick();

private:
  ///The amino acid texts
  std::vector<sf::Text> m_amino_acid_texts;

  ///The center text
  sf::Text m_center_text;

  ///Will music be played?
  bool m_do_play_music;

  ///The font for all texts
  sf::Font m_font;

  ///The logic behind this menu
  choose_amino_acids_menu m_menu;

  ///Music played, starts at constructor, ends at destructor
  sf::Music m_music;

  ///The player texts
  std::vector<sf::Text> m_player_texts;

  ///The AminoAcidFighter sprites
  ///They are non-const, as they are modified before drawing
  Sprites_sfml& m_sprites;

  ///In which state is the program while and directly after this menu?
  program_state m_state;

  ///Window used for displayal
  sf::RenderWindow& m_window;

  ///Show this menu on the screen
  void display();

  ///Process a single event
  void process_event(const sf::Event& event);
};

std::vector<player> choose_aminoacids(
  sf::RenderWindow& window,
  std::vector<amino_acid> amino_acids
);

void check_joystick_press(choose_amino_acids_menu &m_menu);
void check_keyboard_press(choose_amino_acids_menu &m_menu);

#endif // CHOOSE_AMINO_ACIDS_MENU_SFML_H
