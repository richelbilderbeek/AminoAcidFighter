#ifndef POWER_TYPE_H
#define POWER_TYPE_H

#include "bullet.h"

enum class power_type
{
  ceasefire, // no one can shoot except you
  crash, // player is able to hurt other players by bumping
  freeze_all, // save the current momentum, results in 5 sec standstill
  freeze_player, // own player is frozen
  health, // get health at a certain moment or hit
  homing_missile, // Choose player that gets certain damage
  invisibility, // become invisible
  invisible_bullets, // shoot sdddsnvisible bullets
  kamikaze, // everybody gets hit, including the player itself
  maximize, // maximize other players
  mine, // put invisible mine
  minimize, // become smaller
  mix_speed, // reverse speed_x and speed_y
  multi_shot, // shoot 4 bullets at once
  opposite_switch, // turn 180 degrees
  power_shot, // more powerfull shot
  repell, // all bullets within a certain range are repelled (or removed)
  reverse_speed, // go into the opposite direction
  reverse_controls, // left becomes right, right becomes left for 5 sec (for the other players)
  shield, // a temporary (5 sec) shield
  slowdown, // slow down all players
  spin, // fast spin other players
  stop_bullets, // bullets stop moving
  strafe_left, // move sideways to the left
  strafe_right, // move sideways to the right
  switch_players, // switch player locations
  teleport, // teleport to set location
  turbo_boost // extra speed
};

class game;

void do_health (game& g, const int i);
void do_kamikaze (game& g);
void do_mix_speed(game& g);
void do_opposite_switch(game& g);
void do_reverse_speed(game& g);

void do_slowdown(game& g);
void do_switch_players(game& g);
void do_teleport (game& g, const int i);
void do_turbo_boost (game& g);

///How many ticks do the power_types last?
///Some of them only last only one tick
int get_duration(const power_type any_power);

#endif // POWER_H
