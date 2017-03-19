#ifndef MENU_H
#define MENU_H

#include <vector>
#include "amino_acid.h"

/// Menu in which the amino acids are chosen.
/// The number of amino acids
/// cannot be changed in this menu
class menu
{
public:
  /// The initial amino acids. The number of amino acids
  /// cannot be changed in this menu
  menu(const std::vector<amino_acid>& initial_amino_acids);

  /// Player with index 'player_index' chooses the next amino acid
  /// Will throw if that player does not exist
  void choose_next(const int player_index);

  /// Player with index 'player_index' chooses the next amino acid
  /// Will throw if that player does not exist
  void choose_previous(const int player_index);

  ///The amino acids now
  const auto& get_current_amino_acids() const noexcept { return m_amino_acids; }

private:

  std::vector<amino_acid> m_amino_acids;
};

void minus_player(
  int &player_amount
);

void plus_player(
  int &player_amount
);


#endif // MENU_H
