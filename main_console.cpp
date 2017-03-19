#include <cassert>

#include "amino_acid.h"
#include "game.h"
#include "helper.h"

int main()
{
  game g( { amino_acid::alanine, amino_acid::alanine } );
  std::cout << g << '\n';
  g.tick();
  std::cout << g << '\n';
  //g.press_key(0, left
  //g.is_game_over()
  //g.has_won()

}


