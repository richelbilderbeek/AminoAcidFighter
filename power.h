#ifndef POWER_H
#define POWER_H

#include "power_type.h"

/// game keeps a collection of powers
/// that are active
class power
{
public:
  power(
    int end_frame,
    int player_index,
    power_type type
  );

  auto get_endframe() const noexcept { return m_endframe; }
  auto get_player_index() const noexcept { return m_player_index; }
  auto get_type() const noexcept { return m_type; }

private:
  int m_endframe;
  int m_player_index;
  power_type m_type;
};

///Let a player do a power on the game
/// @param any_power the power the player chooses to perform
/// @param game the game the power is used on
/// @param player_index the index of the player, will throw
///   if that index does not exist
void do_power(const power_type any_power, game& g, const int player_index);

#endif // POWER_H
