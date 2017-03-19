#include "menu.h"

menu::menu(
  const std::vector<amino_acid>& initial_amino_acids
)
  : m_amino_acids{initial_amino_acids}
{
}

void menu::choose_next(const int player_index)
{
  m_amino_acids[player_index] = get_next(m_amino_acids[player_index]);
}

void menu::choose_previous(const int player_index)
{
  m_amino_acids[player_index] = get_prev(m_amino_acids[player_index]);
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


