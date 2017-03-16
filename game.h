#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "amino_acid.h"
#include "menu.h"
#include "program_state.h"

///Outer game loop: runs the full program, including the menus
void run(
  sf::RenderWindow &window,
  const int window_size,
  const int argc);

#endif // GAME_H
