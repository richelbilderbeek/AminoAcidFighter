#ifndef GAME_SFML_H
#define GAME_SFML_H

/// Functions and/or classes to display the 'game' class
/// using SFML

#include <SFML/Graphics.hpp>
#include <vector>

#include "bullet.h"
#include "player.h"
#include "program_state.h"

void bullet_hits_player(
  std::vector<bullet> &bullets,
  std::vector<player> &ps,
  std::vector<sf::RectangleShape> &life_bars
);

std::vector<player> create_game_players(
  std::vector<amino_acid> aas,
  std::vector<sf::Vector2f> ps_pos
);

void draw_game_components(
  sf::RenderWindow &w,
  std::vector<sf::RectangleShape> life_bars,
  std::vector<sf::CircleShape> hit_ranges,
  std::vector<bullet> bullets
);

std::array<sf::Vector2f, 4> get_life_bar_positions();

std::vector<sf::Vector2f> get_start_positions();

void display(
  sf::RenderWindow &w,
  const int window_size,
  const std::vector<amino_acid> aas
);

/// @param kill_frame the frame at which the game will be terminated
///   if 'kill_frame' is negative, the game will not be terminated
void display(
  sf::RenderWindow &w,
  const int window_size,
  const std::vector<player> ps,
  const int kill_frame = -1
);

void process_event_game(
  sf::Event event,
  sf::RenderWindow &w,
  std::vector<player> &ps,
  std::vector<bullet> &bullets,
  const int window_size
);

///Outer game loop: runs the full program, including the menus
void run(
  sf::RenderWindow &w,
  const int window_size,
  const bool do_play_music
);

void run_profile(
  sf::RenderWindow &w,
  const int window_size
);

std::vector<sf::CircleShape> set_hit_ranges(
  std::vector<player> ps,
  std::vector<sf::Vector2f> start_positions);

std::vector<sf::RectangleShape> set_life_bars(
  int player_amount,
  std::array<sf::Vector2f, 4> life_bar_positions
);

program_state run_choose_n_player_menu(
  sf::RenderWindow &w,
  bool do_play_music,
  std::vector<amino_acid> &amino_acids);

program_state run_choose_amino_acids_menu(
  sf::RenderWindow &w,
  bool do_play_music,
  std::vector<amino_acid> &amino_acids);

#endif // GAME_SFML_H