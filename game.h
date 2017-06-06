#ifndef GAME_H
#define GAME_H

/// Functions and/or classes to do the game logic,
/// without its displayal

#include "action.h"
#include "amino_acid.h"
#include "choose_amino_acids_menu.h"
#include "game_state.h"
#include "player.h"
#include "program_state.h"

class game
{
public:
  game(
    std::vector<amino_acid>& players,
    const double world_size
  );

  void do_action(int i, action any_action);
  const std::vector<bullet>& get_bullets() const noexcept { return m_bullets; }
  std::vector<bullet>& get_bullets() noexcept { return m_bullets; }
  game_state get_state() { return m_state; }

  const auto& get_players() const noexcept { return m_players; }
  auto& get_players() noexcept { return m_players; }

  auto get_world_size() const noexcept { return m_world_size; }
  auto set_bullets(std::vector<bullet> bullets) { m_bullets = bullets; }

  ///Do a game 'tick', e.g. do this 60 times per second
  void tick();

private:
  ///All bullets currently in the game
  std::vector<bullet> m_bullets;

  std::vector<player> m_players;
  game_state m_state;
  double m_world_size;

  ///Check if one of the players is hit by a bullet
  void bullet_hits_player();

  void do_damage();
};

///Calculates the distance between a bullet and a player
float calculate_distance_bullet_player(
  bullet any_bullet,
  player any_player
);

///Collect the hitpoints of the players
std::vector<double> collect_hit_points(const game& g);

/// Create the 2,3 or 4 players at the right initial positions,
std::vector<player> create_players(
  const std::vector<amino_acid>& amino_acids,
  const int world_size
);

/// Create a test game
game create_test_game_1();

const std::vector<bullet>& get_bullets(const game& g);
std::vector<bullet>& get_bullets(game& g);

const std::vector<player>& get_players(const game& g);
std::vector<player>& get_players(game& g);

///Display the game state
std::ostream& operator<<(std::ostream& os, const game& g) noexcept;

#endif // GAME_H
