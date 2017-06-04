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
  ///Starts either a normal or profile run.
  /// @param args the command-line arguments as passed from the main function.
  ///   as usual, args[0] contains the full path to the executable. If at least
  ///   one arguments equals '--profile', a profile run is started. '--help'
  ///   shows all options
  program_sfml(const std::vector<std::string>& args);

  ~program_sfml();

  ///The main program loop, ends when either (1) the user quits the program,
  /// (2) the profile run hits its kill frame
  void run();

private:

  ///The amino acid types chosen by the users;
  std::vector<amino_acid> m_amino_acids;

  ///The command line arguments, as obtained in the constructor
  const std::vector<std::string> m_args;

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

  ///Show the winner of the last battle
  void run_winner_screen();
};


#endif // PROGRAM_SFML_H
