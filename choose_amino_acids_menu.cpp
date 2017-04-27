#include <stdexcept>
#include "choose_amino_acids_menu.h"

choose_amino_acids_menu::choose_amino_acids_menu(
  const std::vector<amino_acid>& initial_aas,
  bool /* play_music */
)
  : m_amino_acids{initial_aas}
{
  if(initial_aas.size() < 2 ||
     initial_aas.size() > 4)
  {
    throw std::invalid_argument("Too many or too little amino_acids");
  }
}

void choose_amino_acids_menu::choose_next(const int player_index)
{
  if(player_index < 0 ||
     player_index >= static_cast<int>(m_amino_acids.size()))
  {
    throw std::invalid_argument("Invalid player");
  }
  m_amino_acids[player_index] = get_next(m_amino_acids[player_index]);
}

void choose_amino_acids_menu::choose_previous(const int player_index)
{
  if(player_index < 0 ||
     player_index >= static_cast<int>(m_amino_acids.size()))
  {
    throw std::invalid_argument("Invalid player");
  }
  m_amino_acids[player_index] = get_prev(m_amino_acids[player_index]);
}

choose_amino_acids_menu create_test_menu_1()
{
  const std::vector<amino_acid> initial_aas =
  {
    amino_acid::threonine,
    amino_acid::arginine,
    amino_acid::phenylalanine
  };
  return choose_amino_acids_menu{initial_aas};
}
