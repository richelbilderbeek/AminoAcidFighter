#ifndef GAME_H
#define GAME_H

/// Functions and/or classes to do the game logic,
/// without its displayal

#include "action.h"
#include "amino_acid.h"
#include "menu.h"
#include "player.h"
#include "program_state.h"

class game
{
public:
  game(
    const std::vector<amino_acid>& players,
    const double world_size
  );

  const auto& get_bullets() const noexcept { return m_bullets; }
  auto& get_bullets() noexcept { return m_bullets; }
  const auto& get_players() const noexcept { return m_players; }
  auto get_world_size() const noexcept { return m_world_size; }
  void do_action(int i, action any_action);

  ///Do a game 'tick', e.g. do this 60 times per second
  void tick();

private:
  std::vector<bullet> m_bullets;
  std::vector<player> m_players;
  double m_world_size;
};

///Calculates the distance between a bullet and a player
float calculate_distance_bullet_player(
  bullet any_bullet,
  player any_player
);

/// Create the 2,3 or 4 players at the right initial positions,
std::vector<player> create_players(
  const std::vector<amino_acid>& amino_acids,
  const double world_size
);

/// Create a test game
game create_test_game_1();

///Display the game state
std::ostream& operator<<(std::ostream& os, const game& g) noexcept;

#endif // GAME_H
