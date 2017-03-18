#include "amino_acid.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(get_next_on_valine_does_nothing)
{
  BOOST_CHECK(get_next(amino_acid::valine) == amino_acid::valine);
}

BOOST_AUTO_TEST_CASE(get_prev_on_alanine_does_nothing)
{
  BOOST_CHECK(get_prev(amino_acid::alanine) == amino_acid::alanine);
}

BOOST_AUTO_TEST_CASE(get_next_and_get_prev_are_symmetrical)
{
  BOOST_CHECK(get_next(get_prev(amino_acid::glycine)) == amino_acid::glycine);
}

BOOST_AUTO_TEST_CASE(glycine_to_str)
{
  BOOST_CHECK_EQUAL(to_str(amino_acid::glycine), "Glycine");
}
