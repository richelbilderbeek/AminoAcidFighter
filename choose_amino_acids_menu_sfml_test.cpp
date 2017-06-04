#include "choose_amino_acids_menu_sfml.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(choose_amino_acids_menu_sfml_construction)
{
  sf::RenderWindow w;
  Sprites_sfml sprites;
  choose_amino_acids_menu_sfml m(w, sprites);
  m.tick();
}

