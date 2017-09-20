#ifndef GAME_H
#define GAME_H

/// Functions and/or classes to do the game logic,
/// without its displayal

#include "action.h"
#include "amino_acid.h"
#include "bullet.h"
#include "choose_amino_acids_menu.h"
#include "game_state.h"
#include "player.h"
#include "power.h"
#include "program_state.h"

class game
{
public:
  ///@param world_size size of the (square) world in pixels
  game(
    const std::vector<amino_acid>& players,
    const int world_size,
    const bool do_play_music,
    const bool is_profile_run
  );

  /// @param player_index the player's index, thus 0 for player 1
  /// Will throw if i does not exist
  void do_action(const int player_index, const action any_action);

  #ifdef THINK_THIS_IS_A_GREAT_IDEA_20170920
  /// @param i the player's index, thus 0 for player 1
  /// Will throw if i does not exist
  void activate_power(const int player_index, const power_type t);
  #endif //THINK_THIS_IS_A_GREAT_IDEA_20170920

  const std::vector<bullet>& get_bullets() const noexcept { return m_bullets; }
  std::vector<bullet>& get_bullets() noexcept { return m_bullets; }
  bool get_do_play_music() const noexcept { return m_do_play_music; }
  game_state get_game_state() const noexcept { return m_game_state; }
  program_state get_state() const  noexcept { return m_state; }

  bool get_is_profile_run() const noexcept { return m_is_profile_run; }

  const auto& get_players() const noexcept { return m_players; }
  auto& get_players() noexcept { return m_players; }

  ///Get the powers active in the game
  const auto& get_powers() const noexcept { return m_active_powers; }

  auto get_world_size() const noexcept { return m_world_size; }
  auto set_bullets(std::vector<bullet> bullets) { m_bullets = bullets; }
  auto set_players(std::vector<player> players) { m_players = players; }
  void set_state(program_state p) { m_state = p; }

  ///Do a game 'tick', e.g. do this 60 times per second
  void tick();

private:

  ///Powers that are currently active in the game
  std::vector<power> m_active_powers;

  ///All bullets currently in the game
  std::vector<bullet> m_bullets;

  ///Will music be played?
  bool m_do_play_music;

  ///Current frame, is increased every tick
  int m_frame;

  ///Current state
  game_state m_game_state;

  ///Is this a profile run, yes or no?
  bool m_is_profile_run;

  std::vector<player> m_players;

  ///In which state is the program while and directly after the battle?
  program_state m_state;

  ///The size of the (square) world in pixels
  int m_world_size;

  void do_damage();
};

///Calculates the distance between a bullet and a player
double calculate_distance(
  const bullet& any_bullet,
  const player& any_player
);

///Collect the hitpoints of the players
std::vector<double> collect_hit_points(const game& g);

std::vector<double> collect_player_speed_xs(const game& g);
std::vector<double> collect_player_speed_ys(const game& g);

///Count the numberof bullets currently in the game
int count_bullets(const game& g) noexcept;

///Count the number of bullets that are moving
int count_moving_bullets(const game& g) noexcept;

/// Create the 2,3 or 4 players at the right initial positions,
std::vector<player> create_players(
  const std::vector<amino_acid>& amino_acids,
  const int world_size
);

/// Create a minimal test game with a minimum of action going on
game create_test_game_1();

/// Create a game with a maximum of action going on
game create_test_game_2();

std::vector<amino_acid> get_amino_acids(const game& g);

///Get the amino acid type of a player
///Will throw if there is no player with that index
amino_acid get_amino_acid(const game& g, const int player_index);

const std::vector<bullet>& get_bullets(const game& g);
std::vector<bullet>& get_bullets(game& g);

bool get_do_play_music(const game& g);
bool get_is_profile_run(const game& g);

///Get the number of players
int get_n_players(const game& g);

///Will throw if there is no player with that index
const player& get_player(const game& g, const int player_index);

///Will throw if there is no player with that index
player& get_player(game& g, const int player_index);

const std::vector<player>& get_players(const game& g);
std::vector<player>& get_players(game& g);

///Get the power type of a player
power_type get_power(const game& g, const int player_index);

program_state get_state(const game& g);

///Is a certain power type active in the game?
bool has_power(const game& g, const power_type t);

///Is there a cease fire (no shooting allowed) active?
bool is_cease_fire(const game& g) noexcept;

void set_state(game& g, program_state p);

///Stop all the bullets
void stop_bullets(game &g);

///Display the game state
std::ostream& operator<<(std::ostream& os, const game& g) noexcept;

bool operator==(const game& lhs, const game& rhs) noexcept;

#endif // GAME_H
