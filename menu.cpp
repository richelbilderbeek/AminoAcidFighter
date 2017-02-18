#include "menu.h"

void press_down(
  int &player_amount)
{
    --player_amount;
    std::cout<< "Down";
}

void press_up(
  int &player_amount)
{
    ++player_amount;
    std::cout<< "Up";
}
