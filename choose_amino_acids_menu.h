#ifndef CHOOSE_AMINO_ACIDS_MENU_H
#define CHOOSE_AMINO_ACIDS_MENU_H

#include <vector>
#include "amino_acid.h"

/// Menu in which the amino acids are chosen.
/// The number of amino acids
/// cannot be changed in this menu
class choose_amino_acids_menu
{
public:
  /// The initial amino acids. The number of amino acids
  /// cannot be changed in this menu
  /// @param play_music do play music when the menu is displayed
  choose_amino_acids_menu(
    const std::vector<amino_acid>& initial_amino_acids,
    bool play_music = true
  );

  /// Player with index 'player_index' chooses the next amino acid
  /// Will throw if that player does not exist
  void choose_next(const int player_index);

  /// Player with index 'player_index' chooses the next amino acid
  /// Will throw if that player does not exist
  void choose_previous(const int player_index);

  bool play_music() const noexcept { return m_play_music; }

  ///The amino acids now
  const auto& get_current_amino_acids() const noexcept { return m_amino_acids; }

private:

  /// The amino acids that are currently chosen by the players
  std::vector<amino_acid> m_amino_acids;

  /// Play the Amino Acid Fighter tune?
  bool m_play_music;
};

///Create a testing menu
choose_amino_acids_menu create_test_menu_1();

#endif // CHOOSE_AMINO_ACIDS_MENU_H
