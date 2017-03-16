#ifndef MENU_H
#define MENU_H

#include <array>
#include <cassert>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "amino_acid.h"
#include "game.h"
#include "player.h"
#include "program_state.h"

void change_amino_name(
  amino_acid aminoacid_player,
  sf::Text &player_AA
);

///Return the selected amino acids
std::vector<amino_acid> choose_aminoacids(
  sf::RenderWindow &window,
  const int argc,
  std::vector<amino_acid> players);

///Menu for selecting a number of players
///Return chosen number of players
int choose_n_players(
  sf::RenderWindow &window,
  const int argc,
  int player_amount
);

void choose_player_joystick(
  std::vector<amino_acid> &amino_acids,
  std::vector<sf::Text> &texts,
  std::vector<player> &players,
  std::array<sf::Vector2f, 4> player_positions
);

void choose_player_keyboard(
  std::vector<amino_acid> &amino_acids,
  std::vector<sf::Text> &texts,
  std::vector<player> &players,
  std::array<sf::Vector2f, 4> player_positions
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

void minus_player(
  int &player_amount
);

void plus_player(
  int &player_amount
);

program_state process_event_AA_choice(
  sf::Event &event,
  sf::RenderWindow &window,
  std::vector<amino_acid> &amino_acids,
  std::vector<sf::Text> &AA_texts,
  std::vector<player> &players,
  std::array<sf::Vector2f, 4> player_positions);

program_state process_event_select_n_players(
  const sf::Event &event,
  sf::RenderWindow& window,
  int& player_amount);

std::vector<sf::Text> set_AA_texts(
  sf::Font &font,
  std::array<sf::Vector2f, 4> text_AA_positions,
  std::array<sf::Color, 4> text_colors,
  std::vector<amino_acid> amino_acids
);

std::vector<player> set_players(
  std::vector<amino_acid> amino_acids,
  std::array<sf::Vector2f, 4> player_positions
);

std::array<sf::Vector2f, 4> set_player_positions     ();
std::array<sf::Color   , 4> set_text_colors          ();
std::array<sf::Vector2f, 4> set_text_AA_positions    ();
std::array<sf::Vector2f, 4> set_text_player_positions();

#endif // MENU_H
