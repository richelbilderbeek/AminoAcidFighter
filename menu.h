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

void minus_player(
  int &player_amount);

void plus_player(
  int &player_amount);

void menu_choose_aminoacid(
  sf::RenderWindow &window,
  bool &menu_amino_acids,
  bool &game_screen,
  int argc);

void menu_choose_player_amount(
  sf::RenderWindow &window,
  bool &menu_players,
  bool &menu_amino_acids,
  int argc);

void draw_player_text(
  std::string text,
  sf::Vector2f position,
  sf::RenderWindow &window,
  sf::Color color);


#endif // MENU_H
