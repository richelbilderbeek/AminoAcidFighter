#include "power.h"

int get_duration(const power any_power)
{
  switch (any_power)
  {
    case power::shield: return 10;
    default: return 0;
  }
  //Not implemented yet
  return 0;
}
