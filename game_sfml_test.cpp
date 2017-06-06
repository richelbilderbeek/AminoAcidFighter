#include "game_sfml.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(game_sfml_construction)
{
  sf::RenderWindow w{
    sf::VideoMode(600, 600), //Window is 600 x 600 pixels
    "game_sfml_construction",
    sf::Style::Titlebar | sf::Style::Close
  };

  const bool do_play_music{false};
  const std::vector<amino_acid> amino_acids =
  {
    amino_acid::alanine, amino_acid::arginine
  };
  const bool is_profile_run{false};
  Sprites_sfml sprites;

  game_sfml g(
    w,
    amino_acids,
    sprites
  );
  /* TODO
  BOOST_CHECK_EQUAL(do_play_music, w.do_play_music());
  BOOST_CHECK_EQUAL(amino_acids, w.get_amino_acids());
  BOOST_CHECK_EQUAL(is_profile_run, w.is_profile_run());
  */
  g.tick();
}

