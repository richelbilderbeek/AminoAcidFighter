#ifndef POWER_H
#define POWER_H

#include "power_type.h"

class power
{
public:
  power(
    int end_frame,
    int player_index,
    power_type type
  );

private:
  int m_endframe;
  int m_player_index;
  power_type m_type;
};

void do_power(power_type any_power, game& g, int i);

#endif // POWER_H
