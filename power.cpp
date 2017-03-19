#include "power.h"

int get_duration(const power any_power)
{
  switch (any_power)
  {
    case shield: return 10;
  }
  //Not implemented yet
  return 0;
}
