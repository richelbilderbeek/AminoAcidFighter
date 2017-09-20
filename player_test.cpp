#include <boost/test/unit_test.hpp>
#include "helper.h"
#include "player.h"
#include "game.h"

BOOST_AUTO_TEST_CASE(player_construction)
{
  const amino_acid any_amino_acid = amino_acid::cysteine;
  const double x{12.34};
  const double y{23.45};
  const player p(
    any_amino_acid,
    x,
    y
  );

  BOOST_CHECK(p.get_amino_acid() == any_amino_acid);
  BOOST_CHECK_EQUAL(p.get_x(), x);
  BOOST_CHECK_EQUAL(p.get_y(), y);
}

BOOST_AUTO_TEST_CASE(tyrosine_has_shield_as_special_power)
{
  BOOST_CHECK(get_power(amino_acid::tyrosine) == power::shield);
}

BOOST_AUTO_TEST_CASE(player_start_using_power_starts_using_power)
{
  game g = create_test_game_1();
  player& p = get_player(g, 0);
  BOOST_CHECK(!p.uses_power());
  p.start_using_power(g);
  BOOST_CHECK(p.uses_power());
}

BOOST_AUTO_TEST_CASE(player_using_power_has_a_duration)
{
  game g = create_test_game_1();
  player& p = get_player(g, 0);
  p.start_using_power(g);
  BOOST_CHECK(p.uses_power());
  for (int i=0; i!=100; ++i)
  {
    g.tick();
  }
  BOOST_CHECK(!p.uses_power());
}
