#ifndef GAME_SFML_H
#define GAME_SFML_H

/// Functions and/or classes to display the 'game' class
/// using SFML

#include "bullet.h"
#include "player.h"
#include <SFML/Graphics.hpp>

void bullet_hits_player(
  std::vector<bullet> bullets,
  std::vector<player> players,
  std::vector<sf::RectangleShape> &life_bars
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

std::vector<player> create_menu_players(
  std::vector<amino_acid> amino_acids,
  std::vector<sf::Vector2f> player_positions
);

std::vector<sf::Vector2f> set_start_positions();

void substract_HP(
  std::vector<sf::RectangleShape> &life_bars,
  int i
);


#endif // GAME_SFML_H
