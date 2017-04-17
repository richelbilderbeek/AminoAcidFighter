#include "power.h"

int get_duration(const power any_power) //!OCLINT cannot make this any shorter
{
  switch (any_power)
  {
    case power::freeze_player: return 10;
    case power::anti_freeze_player: return 10;
    case power::reverse_speed: return 10;
    case power::mix_speed: return 10;
    case power::reversed_controls: return 10;
    case power::strafe_left: return 10;
    case power::strafe_right: return 10;
    case power::shield: return 10;
    case power::side_shoot: return 10;
    case power::turbo_boost: return 10;
    case power::slowdown: return 10;
    case power::homing_missile: return 10;
    case power::power_shot: return 10;
    case power::kamikaze: return 10;
    case power::freeze_all: return 10;
    case power::anti_freeze_all: return 10;
    case power::minimize: return 10;
    case power::maximize: return 10;
    case power::switch_players: return 10;
    case power::crash: return 10;
  }
  //Not implemented yet
  return 0;
}
