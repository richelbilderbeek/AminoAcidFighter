#include <algorithm>
#include <cassert>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game_state.h"
#include "amino_acid.h"
#include "bullet.h"
#include "menu.h"
#include "player.h"

int main(int argc, char * argv[])
{  
  const int window_size = 600;

  sf::RenderWindow window(
    sf::VideoMode(window_size, window_size),
    "AminoAcidFighter",
    sf::Style::Titlebar | sf::Style::Close);

  window.setFramerateLimit(60);

  run(
    window,
    window_size,
    argc);
}


