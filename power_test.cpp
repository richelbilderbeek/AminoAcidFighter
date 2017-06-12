#include <boost/test/unit_test.hpp>
#include "power.h"
#include "game.h"

BOOST_AUTO_TEST_CASE(do_stop_bullets_must_stop_bullets)
{
  game g = create_test_game_2();

  //There are moving bullets
  //NE: Not Equal
  BOOST_CHECK_NE(count_moving_bullets(g), 0);

  do_stop_bullets(g);

  //There are no moving bullets anymore
  BOOST_CHECK_EQUAL(count_moving_bullets(g), 0);
}


