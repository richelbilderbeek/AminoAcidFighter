#include "menu.h"

menu create_test_menu_1()
{
  const std::vector<amino_acid> initial_amino_acids =
  {
    amino_acid::threonine,
    amino_acid::arginine,
    amino_acid::phenylalanine
  };
  return menu m{initial_amino_acids};
}

void minus_player(
  int &player_amount)
{
    --player_amount;
}

void plus_player(
  int &player_amount)
{
    ++player_amount;
}


