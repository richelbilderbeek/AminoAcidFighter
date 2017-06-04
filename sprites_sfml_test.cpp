#include "sprites_sfml.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sprites_sfml_construction)
{
  Sprites_sfml sprites;
  const auto amino_acids = get_all_amino_acids();
  for (const auto amino_acid: amino_acids)
  {
    const sf::Sprite& sprite = sprites.get(amino_acid);
    BOOST_CHECK(sprite.getTexture());
  }
  BOOST_CHECK(sprites.get_bullet().getTexture());
}
