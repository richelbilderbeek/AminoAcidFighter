#ifndef MENU_H
#define MENU_H

#include <cassert>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "amino_acid.h"
#include "player.h"

void change_amino_name(
  amino_acid aminoacid_player,
  sf::Text &player_AA);

void draw_text(std::string text,
  sf::Vector2f position,
  sf::RenderWindow &window,
  sf::Color color,
  int size);

void minus_player(
  int &player_amount);

///Return the selected amino acids
std::vector<amino_acid> menu_choose_aminoacid(
  sf::RenderWindow &window,
  const int argc,
  const std::vector<amino_acid>& players);

///Return chosen number of players
int menu_choose_player_amount(
  sf::RenderWindow &window,
  const int argc,
  const int player_amount);

void play_game(
  sf::RenderWindow &window,
  const int window_size,
  const std::vector<amino_acid>& players
);

void plus_player(
  int &player_amount);

void process_event_select_n_players(const sf::Event& event, sf::RenderWindow& window, int& player_amount, bool& menu_players, bool& menu_amino_acids);

///Outer game loop: runs the full program, including the menus
void run(
  sf::RenderWindow &window,
  const int window_size,
  const int argc
);

#endif // MENU_H
