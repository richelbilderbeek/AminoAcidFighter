#include "game.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(check_create_players)
{
  const double world_size{314.159};
  const std::vector<amino_acid> amino_acids =
  {
    amino_acid::isoleucine,
    amino_acid::tryptophan,
    amino_acid::arginine,
    amino_acid::asparagine
  };
  const auto players = create_players(amino_acids, world_size);

  BOOST_CHECK(players.size() == amino_acids.size());
  // Players must be arranged like
  //
  //  [0]  [1]
  //
  //  [2]  [3]
  //
  // in the world
  BOOST_CHECK_EQUAL(players[0].get_x(), players[2].get_x());
  BOOST_CHECK_EQUAL(players[1].get_x(), players[3].get_x());

  BOOST_CHECK_EQUAL(players[0].get_y(), players[1].get_y());
  BOOST_CHECK_EQUAL(players[2].get_y(), players[3].get_y());

  BOOST_CHECK_NE(players[0].get_x(), players[1].get_x());
  BOOST_CHECK_NE(players[0].get_y(), players[2].get_y());
}

BOOST_AUTO_TEST_CASE(check_game_construction)
{
  const double world_size{314.159};
  const std::vector<amino_acid> amino_acids =
  {
    amino_acid::alanine,
    amino_acid::glycine
  };
  const game g(amino_acids, world_size);
  BOOST_CHECK(g.get_players().size() == amino_acids.size());
}



