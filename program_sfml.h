#ifndef PROGRAM_SFML_H
#define PROGRAM_SFML_H

#include <SFML/Graphics.hpp>
#include "sprites_sfml.h"
#include "program_state.h"

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

  ///The amino acid types chosen by the users;
  std::vector<amino_acid> m_amino_acids;

  ///Play music in the menu dialogs?
  const bool m_do_play_music;

  ///Is this a profile run? If false, this is a normal program run
  const bool m_do_profile_run;

  ///All the AminoAcidFighter sprites
  Sprites_sfml m_sprites;

  ///The current active state of the program
  program_state m_state;

  ///The window used throughout the program
  sf::RenderWindow m_window;

  ///Run the battle!
  void run_battle();

  ///Run the menu in which the amino acid types are chosen by the users
  void run_choose_amino_acids_menu();

  ///Run the menu in which the number of players is chosen by the user
  void run_choose_n_player_menu();

  ///The normal main program loop
  void run_normal();

  ///The profiling program loop, stops after some time without user interaction
  void run_profile();

  ///Show the winner of the last battle
  void run_winner_screen();
};

#endif // PROGRAM_SFML_H
