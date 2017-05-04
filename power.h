#ifndef POWER_H
#define POWER_H

enum class power
{
  freeze_player, // save the current momentum, results in standstill
  anti_freeze_player, // take the speed of the stored momentum again
  reverse_speed, // go into the opposite direction (speed_x becomes -speed_x)
  mix_speed, // reverse speed_x and speed_y
  reversed_controls,
  strafe_left, // move sideways to the left
  strafe_right, // move sideways to the right
  shield, //a temporary shield
  side_shoot, // shoot sideways
  turbo_boost,
  slowdown,
  homing_missile, // Choose player that gets certain damage
  power_shot, // more powerfull shot
  kamikaze, // everybody gets hit, including the player itself
  freeze_all, // all players are stuck at their position
  anti_freeze_all,
  minimize,
  maximize,
  switch_players,
  crash // player is able to hurt other players by bumping
};

///How many ticks do the powers last?
///Some of them only last only one tick
int get_duration(const power any_power);

#endif // POWER_H
