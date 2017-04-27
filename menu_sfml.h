#ifndef MENU_SFML_H
#define MENU_SFML_H

/// Functions and/or classes to display the 'menu' class
/// using SFML

#include <array>
#include <cassert>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "amino_acid.h"
#include "game.h"
#include "player.h"
#include "program_state.h"


/// Displays the menu,
/// returns the selected amino acids chosen
/// If no amino acids are returned, the user wants to quit
std::vector<player> choose_aminoacids(
  sf::RenderWindow &window,
  std::vector<amino_acid> amino_acids,
  bool play_music = true
);

///Menu for selecting a number of players
///Return chosen number of players
///A return value of zero denotes that the user wants to quit
[[deprecated]]
int choose_n_players(
  sf::RenderWindow &window,
  const bool do_play_music,
  int player_amount
);

void change_amino_name(
  amino_acid aminoacid_player,
  sf::Text &player_AA
);

void change_AA_name(
  amino_acid aminoacid,
  sf::Text &AA_text
);

void choose_AA_joystick(
  std::vector<player> &players,
  std::vector<sf::Text> &AA_texts
);

void choose_AA_keyboard(
  std::vector<player> &players,
  std::vector<sf::Text> &AA_texts);

/// Create players to be used in the menu dialog
std::vector<player> create_menu_players(
  std::vector<amino_acid> amino_acids
);

void draw_a_text(
  std::string text,
  sf::Vector2f position,
  sf::RenderWindow &window,
  sf::Color color,
  int size
);

void draw_AA_choice_screen(
  sf::RenderWindow &window,
  std::vector<player> players,
  std::array<sf::Vector2f, 4> text_player_pos,
  std::array<sf::Color, 4> text_colors,
  std::vector<sf::Text> AA_texts
);

std::array<sf::Vector2f, 4> get_aa_menu_positions();
std::array<sf::Color   , 4> get_aa_menu_text_colors();
std::array<sf::Vector2f, 4> get_aa_menu_text_player_positions();
std::array<sf::Vector2f, 4> get_aa_menu_text_positions();

program_state process_event_AA_choice(
  sf::Event &event,
  sf::RenderWindow &w,
  std::vector<sf::Text> &AA_txt,
  std::vector<player> &s
);

program_state process_event_select_n_players(
  const sf::Event &event,
  sf::RenderWindow& window,
  int& player_amount
);

std::vector<sf::Text> set_AA_texts(
  sf::Font &font,
  std::array<sf::Vector2f, 4> text_AA_positions,
  std::array<sf::Color, 4> text_colors,
  std::vector<amino_acid> amino_acids
);

///Plays music
void play_music(sf::Music& music);

#endif // MENU_SFML_H
