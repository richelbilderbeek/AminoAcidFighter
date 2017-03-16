#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "amino_acid.h"
#include "menu.h"
#include "player.h"
#include "program_state.h"

void bullet_hits_player(
  std::vector<bullet> bullets,
  std::vector<player> players,
  std::vector<sf::RectangleShape> &life_bars
);

float calculate_distance_bullet_player(
  bullet bullets,
  player players
);

void draw_game(
  sf::RenderWindow &window,
  std::vector<sf::RectangleShape> life_bars,
  std::vector<sf::CircleShape> hit_ranges,
  std::vector<player> players,
  std::vector<bullet> bullets
);

void play_game(
  sf::RenderWindow &window,
  const int window_size,
  const std::vector<amino_acid>& players
);

void process_event_game(
  sf::Event event,
  sf::RenderWindow &window,
  std::vector<player> &players,
  std::vector<bullet> &bullets,
  const int window_size
);

///Outer game loop: runs the full program, including the menus
void run(
  sf::RenderWindow &window,
  const int window_size,
  const int argc
);

std::vector<sf::CircleShape> set_hit_ranges(
  std::vector<amino_acid> amino_acids,
  std::vector<sf::Vector2f> start_positions
);

std::vector<sf::RectangleShape> set_life_bars(
  std::vector<amino_acid> amino_acids,
  std::array<sf::Vector2f, 4> life_bar_positions
);

std::array<sf::Vector2f, 4> set_life_bar_positions();

std::vector<player> set_players(
  std::vector<amino_acid> amino_acids,
  std::vector<sf::Vector2f> player_positions
);

std::vector<sf::Vector2f> set_start_positions();

#endif // GAME_H
