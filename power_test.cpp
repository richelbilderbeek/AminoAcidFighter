#include <boost/test/unit_test.hpp>
#include "power.h"
#include "game.h"

BOOST_AUTO_TEST_CASE(power_ceasefire_must_ceasefire)
{
  game g = create_test_game_2();

  //What before?

  do_power(power::ceasefire, g);

  //What after?
  BOOST_CHECK(1 == 2); //TODO for Carmen
}

BOOST_AUTO_TEST_CASE(power_crash_must_crash)
{
  game g = create_test_game_2();

  do_power(power::crash, g);
}

BOOST_AUTO_TEST_CASE(power_mix_speed_must_mix_the_speeds)
{
  game g = create_test_game_2();

  const auto speed_xs_before = collect_player_speed_xs(g);
  const auto speed_ys_before = collect_player_speed_ys(g);

  //Reverses the x and y speed of the players
  do_power(power::mix_speed, g);

  const auto speed_xs_after = collect_player_speed_xs(g);
  const auto speed_ys_after = collect_player_speed_ys(g);

  BOOST_CHECK(speed_xs_before == speed_ys_after);
  BOOST_CHECK(speed_ys_before == speed_xs_after);
}

BOOST_AUTO_TEST_CASE(power_stop_bullets_must_stop_bullets)
{
  game g = create_test_game_2();

  //There are moving bullets
  BOOST_CHECK_NE(count_moving_bullets(g), 0);

  do_power(power::stop_bullets, game &g);

  //There are no moving bullets anymore
  BOOST_CHECK_EQUAL(count_moving_bullets(g), 0);
}
