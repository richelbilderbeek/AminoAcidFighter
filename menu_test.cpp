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

BOOST_AUTO_TEST_CASE(menu_construction_with_too_little)
{
  //Cannot create this menu with one amino acid
  const std::vector<amino_acid> initial_amino_acids =
  {
    amino_acid::threonine
  };
  BOOST_CHECK_THROW(
    menu m(initial_amino_acids),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE(menu_construction_with_too_many)
{
  //Cannot create this menu with five amino acids
  const std::vector<amino_acid> initial_amino_acids =
  {
    amino_acid::alanine,
    amino_acid::arginine,
    amino_acid::asparagine,
    amino_acid::aspartic_acid,
    amino_acid::cysteine
  };
  BOOST_CHECK_THROW(
    menu m(initial_amino_acids),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE(menu_choose_for_invalid_players)
{
  menu m = create_test_menu_1();
  BOOST_CHECK_THROW(m.choose_next(-1), std::invalid_argument);
  BOOST_CHECK_THROW(m.choose_previous(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(menu_choose_for_absent_players)
{
  menu m = create_test_menu_1();
  const int n_players = m.get_current_amino_acids().size();
  const int absent_player_index = n_players;
  BOOST_CHECK_THROW(m.choose_next(absent_player_index), std::invalid_argument);
  BOOST_CHECK_THROW(m.choose_previous(absent_player_index), std::invalid_argument);
}


