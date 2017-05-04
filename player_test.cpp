#include <boost/test/unit_test.hpp>
#include "helper.h"
#include "player.h"

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

