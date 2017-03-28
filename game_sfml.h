#ifndef GAME_SFML_H
#define GAME_SFML_H

/// Functions and/or classes to display the 'game' class
/// using SFML

#include <SFML/Graphics.hpp>
#include <vector>
#include "bullet.h"
#include "player.h"

void bullet_hits_player(
  std::vector<bullet> bullets,
  std::vector<player> players,
  std::vector<sf::RectangleShape> &life_bars
);

std::vector<player> create_game_players(
  std::vector<amino_acid> amino_acids,
  std::vector<sf::Vector2f> player_positions
);

void draw_game(
  sf::RenderWindow &window,
  std::vector<sf::RectangleShape> life_bars,
  std::vector<sf::CircleShape> hit_ranges,
  std::vector<player> players,
  std::vector<bullet> bullets
);

std::array<sf::Vector2f, 4> get_life_bar_positions();

std::vector<sf::Vector2f> get_start_positions();

void play_game(sf::RenderWindow &window,
  const int window_size,
  const std::vector<player> players
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
  const bool do_play_music
);

std::vector<sf::CircleShape> set_hit_ranges(
  std::vector<player> players,
  std::vector<sf::Vector2f> start_positions);

std::vector<sf::RectangleShape> set_life_bars(
  int player_amount,
  std::array<sf::Vector2f, 4> life_bar_positions
);

void substract_HP(
  std::vector<sf::RectangleShape> &life_bars,
  int i
);


#endif // GAME_SFML_H
