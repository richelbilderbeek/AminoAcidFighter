#include <cassert>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game_sfml.h"
#include "helper.h"

int main(int argc, char * argv[])
{
  create_resources();
  const int window_size = 600;

  sf::RenderWindow window(
    sf::VideoMode(window_size, window_size),
    "AminoAcidFighter",
    sf::Style::Titlebar | sf::Style::Close);
  Sprites_sfml sprites;
  if (argc == 2 && std::string(argv[1]) == "--profile")
  {
    run_profile(
      window,
      window_size,
      sprites
    );
    return 0;
  }
  window.setFramerateLimit(60);
  const bool do_play_music{argc == 1};
  run(
    window,
    window_size,
    do_play_music,
    sprites);

  window.close();
}

