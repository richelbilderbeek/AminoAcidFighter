#ifndef PROGRAM_SFML_H
#define PROGRAM_SFML_H

#include <SFML/Graphics.hpp>
#include "sprites_sfml.h"

///The full AminoAcidFighte SFML program, that
///handles user interaction going through menus and the game.
class program_sfml
{
public:
  //Constructor
  program_sfml(int argc, char * argv[]);

  //Destructor
  ~program_sfml();

  ///The main program loop, ends when the user quits the program
  void run();

private:

  ///Play music in the menu dialogs?
  bool m_do_play_music;

  ///Is this a profile run? If false, this is a normal program run
  bool m_do_profile_run;

  ///All the AminoAcidFighter sprites
  Sprites_sfml m_sprites;

  ///The window used throughout the program
  sf::RenderWindow m_window;

  ///The normal main program loop
  void run_normal();

  ///The profiling program loop, stops after some time without user interaction
  void run_profile();
};

#endif // PROGRAM_SFML_H
