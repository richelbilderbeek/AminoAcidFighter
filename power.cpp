#include "power.h"

int get_duration(const power any_power) //!OCLINT cannot make this any shorter
{
  switch (any_power)
  {
    case power::ceasefire: return 10;
    case power::crash: return 10;
    case power::freeze_all: return 10;
    case power::freeze_player: return 10;
    case power::health: return 10;
    case power::homing_missile: return 10;
    case power::invisibility: return 10;
    case power::invisible_bullets: return 10;
    case power::kamikaze: return 10;
    case power::maximize: return 10;
    case power::mine: return 10;
    case power::minimize: return 10;
    case power::mix_speed: return 10;
    case power::multi_shot: return 10;
    case power::opposite_switch: return 10;
    case power::power_shot: return 10;
    case power::repell: return 10;
    case power::reverse_speed: return 10;
    case power::reversed_controls: return 10;
    case power::shield: return 10;
    case power::slowdown: return 10;
    case power::spin: return 10;
    case power::stop_bullets: return 10;
    case power::strafe_left: return 10;
    case power::strafe_right: return 10;
    case power::switch_players: return 10;
    case power::teleport: return 10;
    case power::turbo_boost: return 10;
  }
  //Not implemented yet
  return 0;
}


