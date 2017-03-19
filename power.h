#ifndef POWER_H
#define POWER_H

enum class power
{
  store_momentum, // save the current momentum, results in standstill
  release_momentum, // take the speed of the stored momentum again
  reverse_speed, // go into the opposite direction (speed_x becomes -speed_x)
  mix_speed, // reverse speed_x and speed_y
  strafe_left, // move sideways to the left
  strafe_right, // move sideways to the right
  shield, //a temporary shield
  side_shoot, // shoot sideways
  turbo_boost,
  homing_missile,
  power_shot // more powerfull shot
};

///How many ticks do the powers last?
///Some of them only last only one tick
int get_duration(const power any_power);

#endif // POWER_H
