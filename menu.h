#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include "amino_acid.h"
#include "bullet.h"
#include "player.h"

void open_menu_players(sf::RenderWindow &window);
void open_menu_amino_acids(sf::RenderWindow &window);
void open_game_screen(sf::RenderWindow &window, const int window_size);

void press_key(sf::Keyboard key);

void press_up(int &player_amount);

void press_down(int &player_amount);

void press_left();

void press_right();

void get_menu(sf::RenderWindow window, const int window_size, const int menu_players, const int menu_amino_acids, const int game_screen);

#endif // MENU_H
