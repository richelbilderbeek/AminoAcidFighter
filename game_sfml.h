#ifndef GAME_SFML_H
#define GAME_SFML_H

/// Functions and/or classes to display the 'game' class
/// using SFML

#include <SFML/Graphics.hpp>
#include <vector>
#include "bullet.h"
#include "game.h"
#include "player.h"
#include "program_state.h"
#include "sprites_sfml.h"
#include "winner_screen_sfml.h"

class game_sfml
{
public:
  ///Starts the music
  ///@param n_players the initial number of players suggested
  game_sfml(
    sf::RenderWindow& window,
    const bool do_play_music,
    std::vector<amino_acid> amino_acids,
    const bool is_profile_run,
    Sprites_sfml& sprites
  );

  ///Stops the music
  ~game_sfml();

  ///Read the game logic
  const auto& get_game() const noexcept { return m_game; }
  auto& get_game() noexcept { return m_game; }

  ///Obtain the current or state after execute
  program_state get_state() const noexcept { return m_state; }

  ///Runs the battle, which is handling input and displayal.
  ///Closes when the user wants to quit
  ///or continue to winner screen when a player has won.
  ///This can be done by using the get_state member function
  void execute();

  ///Handle input and show this screen once, to be used in testing only
  void tick();

private:
  ///All bullets currently in the game
  std::vector<bullet> m_bullets;

  ///Will music be played?
  bool m_do_play_music;

  ///The logic behind the battle
  game m_game;

  ///The range in which a player can be hit by a bullet
  std::vector<sf::CircleShape> m_hit_ranges;

  ///Is this a profile run, yes or no?
  bool m_is_profile_run;

  ///Life bars of all players
  std::vector<sf::RectangleShape> m_life_bars;

  ///Music played, starts at constructor, ends at destructor
  sf::Music m_music;

  ///The sprites, cannot be const as the sprites are modified in-place
  Sprites_sfml& m_sprites;

  ///In which state is the program while and directly after the battle?
  program_state m_state;

  ///Window used for displayal
  sf::RenderWindow& m_window;

  ///Check if one of the players is hit by a bullet
  void bullet_hits_player();

  ///Show this menu on the screen
  void display();

  ///Process a single event
  void process_event(sf::Event event);
};

std::vector<double> collect_hit_points(const game_sfml& g);

[[deprecated]]
std::vector<player> create_game_players(
  std::vector<amino_acid> amino_acids,
  std::vector<sf::Vector2f> ps_pos
);

void draw_game_components(
  sf::RenderWindow &w,
  std::vector<sf::RectangleShape> life_bars,
  std::vector<sf::CircleShape> hit_ranges,
  std::vector<bullet> bullets
);

std::vector<sf::Vector2f> get_life_bar_positions();

const std::vector<player>& get_players(const game_sfml& g);
std::vector<player>& get_players(game_sfml& g);

std::vector<sf::Vector2f> get_start_positions();

///Get the winner. Returns
/// * -1: everyone died
/// *  0: at least two players are alive
/// *  1: player 1 has won
/// *  2: player 2 has won
/// *  3: player 3 has won
/// *  4: player 4 has won
int get_winner(const game_sfml& g);

void process_event_game(
  sf::Event event,
  std::vector<bullet> &bullets
);

std::vector<sf::CircleShape> set_hit_ranges(
  std::vector<player> ps,
  std::vector<sf::Vector2f> start_positions);

std::vector<sf::RectangleShape> set_life_bars(
  int player_amount,
  std::vector<sf::Vector2f> life_bar_positions
);

#endif // GAME_SFML_H
