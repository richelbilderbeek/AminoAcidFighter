#include <cassert>

#include "action.h"
#include "amino_acid.h"
#include "game.h"
#include "helper.h"

int main()
{
  const double world_size{22.0};
  game g( { amino_acid::alanine, amino_acid::alanine }, world_size );
  std::cout << g << '\n';
  //g.do_action(0, action::accelerate);
  g.do_action(0, action::shoot);
  //g.tick();
  std::cout << g << '\n';
  //g.press_key(0, left
  //g.is_game_over()
  //g.has_won()

}


