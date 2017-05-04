#include "choose_n_players_menu_sfml.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(menu_sfml_can_be_displayed)
{
  sf::RenderWindow w;
  const bool do_play_music{false};
  const int n_players{2};
  choose_n_players_menu_sfml m(w, do_play_music, n_players);
  m.tick();
}

