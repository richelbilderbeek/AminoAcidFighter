#include "choose_n_players_menu_sfml.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(choose_n_players_menu_sfml_construction)
{
  sf::RenderWindow w;
  const bool do_play_music{false};
  const int n_players{3};
  choose_n_players_menu_sfml m(
    w,
    do_play_music,
    n_players
  );
  BOOST_CHECK_EQUAL(m.do_play_music(), do_play_music);
  BOOST_CHECK_EQUAL(m.get_n_players(), n_players);
}

