#ifndef MENU_H
#define MENU_H

#include <cassert>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "amino_acid.h"

#endif // MENU_H

void change_amino_name(
  amino_acid aminoacid_player,
  sf::Text &player_AA);

void press_down(
  int &player_amount);

void press_up(
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
