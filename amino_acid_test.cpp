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
  BOOST_CHECK_EQUAL(to_str(amino_acid::alanine      ), "Alanine"      );
  BOOST_CHECK_EQUAL(to_str(amino_acid::arginine     ), "Arginine"     );
  BOOST_CHECK_EQUAL(to_str(amino_acid::asparagine   ), "Asparagine"   );
  BOOST_CHECK_EQUAL(to_str(amino_acid::aspartic_acid), "Aspartic_acid");
  BOOST_CHECK_EQUAL(to_str(amino_acid::cysteine     ), "Cysteine"     );
  BOOST_CHECK_EQUAL(to_str(amino_acid::glutamic_acid), "Glutamic_acid");
  BOOST_CHECK_EQUAL(to_str(amino_acid::glutamine    ), "Glutamine"    );
  BOOST_CHECK_EQUAL(to_str(amino_acid::glycine      ), "Glycine"      );
  BOOST_CHECK_EQUAL(to_str(amino_acid::histidine    ), "Histidine"    );
  BOOST_CHECK_EQUAL(to_str(amino_acid::isoleucine   ), "Isoleucine"   );
  BOOST_CHECK_EQUAL(to_str(amino_acid::leucine      ), "Leucine"      );
  BOOST_CHECK_EQUAL(to_str(amino_acid::lysine       ), "Lysine"       );
  BOOST_CHECK_EQUAL(to_str(amino_acid::methionine   ), "Methionine"   );
  BOOST_CHECK_EQUAL(to_str(amino_acid::phenylalanine), "Phenylalanine");
  BOOST_CHECK_EQUAL(to_str(amino_acid::proline      ), "Proline"      );
  BOOST_CHECK_EQUAL(to_str(amino_acid::serine       ), "Serine"       );
  BOOST_CHECK_EQUAL(to_str(amino_acid::threonine    ), "Threonine"    );
  BOOST_CHECK_EQUAL(to_str(amino_acid::tryptophan   ), "Tryptophan"   );
  BOOST_CHECK_EQUAL(to_str(amino_acid::tyrosine     ), "Tyrosine"     );
  BOOST_CHECK_EQUAL(to_str(amino_acid::valine       ), "Valine"       );
}
