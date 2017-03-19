#ifndef PLAYER_SFML_H
#define PLAYER_SFML_H

#include <SFML/System/Vector2.hpp>


player create_player(
  amino_acid aminoacid,
  sf::Sprite m_sprite,
  sf::Texture m_texture,
  sf::Vector2f position
);

player create_alanine      (sf::Vector2f position);
player create_arginine     (sf::Vector2f position);
player create_asparagine   (sf::Vector2f position);
player create_aspartic_acid(sf::Vector2f position);
player create_cysteine     (sf::Vector2f position);
player create_glutamic_acid(sf::Vector2f position);
player create_glutamine    (sf::Vector2f position);
player create_glycine      (sf::Vector2f position);
player create_histidine    (sf::Vector2f position);
player create_isoleucine   (sf::Vector2f position);
player create_leucine      (sf::Vector2f position);
player create_lysine       (sf::Vector2f position);
player create_methionine   (sf::Vector2f position);
player create_phenylalanine(sf::Vector2f position);
player create_proline      (sf::Vector2f position);
player create_serine       (sf::Vector2f position);
player create_threonine    (sf::Vector2f position);
player create_tryptophan   (sf::Vector2f position);
player create_tyrosine     (sf::Vector2f position);
player create_valine       (sf::Vector2f position);

void draw(
  player p,
  sf::RenderWindow &window
);

void draw_hit_ranges(
  sf::CircleShape hit_range,
  sf::RenderWindow &window
);

void draw_life_bar(
  sf::RectangleShape life_bars,
  sf::RenderWindow &window
);

void respond_to_joystick(
  player &player3,
  player &player4,
  std::vector<bullet> &bullets,
  int window_size
);

void respond_to_key(
  player &player1,
  player &player2,
  std::vector<bullet> &bullets,
  int window_size
);

#endif // PLAYER_SFML_H
