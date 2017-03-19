#include <cassert>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game_sfml.h"
#include "helper.h"

int main(int argc, char * [])
{
  create_resources();
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

