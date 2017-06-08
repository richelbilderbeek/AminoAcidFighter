#include "game_sfml.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(game_sfml_construction)
{
  sf::RenderWindow w{
    sf::VideoMode(600, 600), //Window is 600 x 600 pixels
    "game_sfml_construction",
    sf::Style::Titlebar | sf::Style::Close
  };

  const std::vector<amino_acid> amino_acids =
  {
    amino_acid::alanine, amino_acid::arginine
  };
  Sprites_sfml sprites;
  const bool do_play_music{false};
  const bool is_profile_run{false};

  game_sfml g(
    w,
    amino_acids,
    sprites,
    do_play_music,
    is_profile_run
  );
  BOOST_CHECK_EQUAL(get_is_profile_run(g), is_profile_run);
  /*
  BOOST_CHECK_EQUAL(amino_acids, w.get_amino_acids());
  BOOST_CHECK_EQUAL(get_do_play_music(g), do_play_musicrun);
  */
  g.tick();
}

