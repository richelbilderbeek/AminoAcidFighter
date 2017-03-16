#include "game.h"

void run(
  sf::RenderWindow &window,
  const int window_size,
  const int argc)
{

  program_state state{program_state::choose_n_players};
  std::vector<amino_acid> players = { amino_acid::alanine, amino_acid::alanine};

  while(window.isOpen()) {
    switch(state) {
      case program_state::choose_n_players: {
        const int new_size = choose_n_players(
          window,
          argc,
          players.size());
        state = program_state::select_players;
        players.resize(new_size); //May result in undefined behavior if size is increased
      }
      break;
      case program_state::select_players: {
        players = choose_aminoacids(
          window,
          argc,
          players);
        state = program_state::battle;
      }
      break;
      case program_state::battle:
        play_game(
          window,
          window_size,
          players);
        assert(!"something should happen now, e.g. a winner screen"); //!OCLINT need to add more screens
      break;
    }
  }
}
