#ifndef PLAYER_SFML_H
#define PLAYER_SFML_H

#include <SFML/Config.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "player.h"

 void draw_players(
  std::vector<player>& ps,
  sf::RenderWindow& w
);

void draw_alanine(
  const player& p,
  sf::RenderWindow& w
);

void draw_arginine(
  const player& p,
  sf::RenderWindow& w
);

void draw_asparagine(
  const player& p,
  sf::RenderWindow& w
);

void draw_aspartic_acid(
  const player& p,
  sf::RenderWindow& w
);

void draw_cysteine(
  const player& p,
  sf::RenderWindow& w
);

void draw_glutamic_acid(
  const player& p,
  sf::RenderWindow& w
);

void draw_glutamine(
  const player& p,
  sf::RenderWindow& w
);

void draw_glycine(
  const player& p,
  sf::RenderWindow& w
);

void draw_histidine(
  const player& p,
  sf::RenderWindow& w
);

void draw_isoleucine(
  const player& p,
  sf::RenderWindow& w
);

void draw_leucine(
  const player& p,
  sf::RenderWindow& w
);

void draw_lysine(
  const player& p,
  sf::RenderWindow& w
);

void draw_methionine(
  const player& p,
  sf::RenderWindow& w
);

void draw_phenylalanine(
  const player& p,
  sf::RenderWindow& w
);

void draw_proline(
  const player& p,
  sf::RenderWindow& w
);

void draw_serine(
  const player& p,
  sf::RenderWindow& w
);

void draw_threonine(
  const player& p,
  sf::RenderWindow& w
);

void draw_tryptophan(
  const player& p,
  sf::RenderWindow& w
);

void draw_tyrosine(
  const player& p,
  sf::RenderWindow& w
);

void draw_valine(
  const player& p,
  sf::RenderWindow& w
);

void draw_hit_ranges(
  sf::CircleShape hit_range,
  sf::RenderWindow &w
);

void draw_life_bar(sf::RectangleShape life_bars,
  sf::RenderWindow &w
);

void respond_to_joystick(
  player &p3,
  player &p4,
  std::vector<bullet> &bullets/*,
  int window_size*/
);

void respond_to_key(
  player &p1,
  player &p2,
  std::vector<bullet> &bullets/*,
  int window_size*/
);

#endif // PLAYER_SFML_H
