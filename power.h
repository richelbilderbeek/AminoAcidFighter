#ifndef POWER_H
#define POWER_H

#include "power_type.h"

class power
{
public:
  power();

private:
  int m_endframe;
  int m_player_index;
  power_type m_type;
};

#endif // POWER_H
