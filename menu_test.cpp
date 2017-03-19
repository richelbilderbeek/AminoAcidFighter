#include "menu.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(menu_construction)
{
  const std::vector<amino_acid> initial_amino_acids =
  {
    amino_acid::threonine,
    amino_acid::arginine,
    amino_acid::phenylalanine
  };
  const menu m(initial_amino_acids);
  BOOST_CHECK(m.get_current_amino_acids() == initial_amino_acids);
}

BOOST_AUTO_TEST_CASE(menu_choose_next)
{
  const std::vector<amino_acid> initial_amino_acids =
  {
    amino_acid::threonine,
    amino_acid::arginine,
    amino_acid::phenylalanine
  };
  menu m(initial_amino_acids);
  assert(m.get_current_amino_acids()[0] == amino_acid::threonine);
  m.choose_next(0);
  BOOST_CHECK(m.get_current_amino_acids()[0] != amino_acid::threonine);
}

BOOST_AUTO_TEST_CASE(menu_choose_previous)
{
  const std::vector<amino_acid> initial_amino_acids =
  {
    amino_acid::threonine,
    amino_acid::arginine,
    amino_acid::phenylalanine
  };
  menu m(initial_amino_acids);
  assert(m.get_current_amino_acids()[1] == amino_acid::arginine);
  m.choose_previous(1);
  BOOST_CHECK(m.get_current_amino_acids()[1] != amino_acid::arginine);
}



