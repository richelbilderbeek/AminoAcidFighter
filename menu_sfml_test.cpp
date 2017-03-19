#include "menu_sfml.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(menu_sfml_can_be_displayed)
{
  const auto window_size = 500;
  sf::RenderWindow window(
    sf::VideoMode(window_size, window_size),
    "AminoAcidFighter",
    sf::Style::Titlebar | sf::Style::Close);

  window.setFramerateLimit(60);
  choose_n_players(window, 2, 2);
}

