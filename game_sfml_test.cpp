#include "game_sfml.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(game_sfml_construction)
{
  Sprites_sfml sprites;
  const game g = create_test_game_1();
  const int world_size{g.get_world_size()};
  sf::RenderWindow w{
    sf::VideoMode(world_size, world_size), //Window is 600 x 600 pixels
    "game_sfml_construction",
    sf::Style::Titlebar | sf::Style::Close
  };

  const game_sfml h(
    w,
    g,
    sprites
  );

  BOOST_CHECK_EQUAL(get_window(h).getSize(), w.getSize());
  BOOST_CHECK_EQUAL(get_game(h), g);
  BOOST_CHECK_EQUAL(get_sprites(h), sprites);
}

