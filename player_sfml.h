#ifndef PLAYER_SFML_H
#define PLAYER_SFML_H

#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include "game.h"
#include "player.h"
#include "sprites_sfml.h"

void draw_player(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

///Indeed, just use a copy of players
void draw_players(
  std::vector<player> ps,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_alanine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_arginine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_asparagine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_aspartic_acid(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_cysteine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_glutamic_acid(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_glutamine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_glycine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_histidine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_isoleucine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_leucine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_lysine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_methionine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_phenylalanine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_proline(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_serine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_threonine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_tryptophan(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_tyrosine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_valine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
);

void draw_hit_ranges(
  sf::CircleShape hit_range,
  sf::RenderWindow& w
);

void draw_life_bar(
  sf::RectangleShape life_bars,
  sf::RenderWindow& w
);

void respond_to_joystick(
  std::vector<player>& players,
  std::vector<bullet>& bullets,
  game& g
);

void respond_to_key(
  std::vector<player>& players,
  std::vector<bullet>& bullets,
  game& g
);


#endif // PLAYER_SFML_H
