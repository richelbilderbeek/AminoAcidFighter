#include "choose_amino_acids_menu_sfml.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(choose_amino_acids_menu_sfml_construction)
{
  sf::RenderWindow w;
  Sprites_sfml sprites;
  const bool do_play_music{false};
  const std::vector<amino_acid> amino_acids =
  {
    amino_acid::alanine, amino_acid::arginine
  };
  choose_amino_acids_menu_sfml m(
    w,
    sprites,
    do_play_music,
    amino_acids
  );
  BOOST_CHECK(m.get_amino_acids() == amino_acids);
  BOOST_CHECK_EQUAL(m.do_play_music(), do_play_music);
  m.tick();
}

