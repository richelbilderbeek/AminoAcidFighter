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

  window.setFramerateLimit(60);
  if (argc == 2 && std::string(argv[1]) == "--profile")
  {
    run_profile(
      window,
      window_size
    );
    return 0;
  }
  const bool do_play_music{argc == 1};
  run(
    window,
    window_size,
    do_play_music);

  window.close();
}

