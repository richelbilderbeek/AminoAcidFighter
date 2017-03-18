#include "amino_acid.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(get_net_and_get_prev_are_ymmetrical)
{
  BOOST_CHECK(get_next(get_prev(amino_acid::glycine)) == amino_acid::glycine);
}

BOOST_AUTO_TEST_CASE(glycine_to_tr)
{
  BOOST_CHECK_EQUAL(to_str(amino_acid::glycine), "Glycine");
}

