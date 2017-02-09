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

void open_menu();
void press_key(sf::Keyboard key);

void press_up(int &player_amount);

void press_down(int &player_amount);

void press_left();

void press_right();

#endif // MENU_H
