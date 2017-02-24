#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "amino_acid.h"
#include "bullet.h"

class player
{
public:
  player(
    sf::Vector2f m_position,
    sf::Sprite * m_sprite,
    sf::Texture * m_texture
  );

  void accellerate();
  void deccellerate();
  auto get_rotation()      const noexcept { return m_sprite->getRotation(); }
  auto get_position()      const noexcept { return m_sprite->getPosition(); }
  const auto& get_sprite() const noexcept { return m_sprite               ; }
  void move(const int m_window_size);
  void set_position(const float x, const float y) noexcept { m_sprite->setPosition(x, y); }
  void set_position(const sf::Vector2f p)         noexcept { m_sprite->setPosition(p)   ; }
  void set_rotation(const float r)                noexcept { m_sprite->setRotation(r)   ; }
  void stop();
  void turn_left();
  void turn_right();

private:
  sf::Vector2f m_position;
  double m_speed_x;
  double m_speed_y;
  sf::Sprite * m_sprite;
  sf::Texture * m_texture;
  ///How fast the sprite is rotating per tick
  double m_turn_speed;
  //int m_window_size;
};

player create_player(
  amino_acid aminoacid,
  sf::Vector2f m_position);

player create_player(
  amino_acid aminoacid,
  sf::Sprite m_sprite,
  sf::Texture m_texture,
  sf::Vector2f m_position);

player create_alanine      (sf::Vector2f m_position);
player create_arginine     (sf::Vector2f m_position);
player create_asparagine   (sf::Vector2f m_position);
player create_aspartic_acid(sf::Vector2f m_position);
player create_cysteine     (sf::Vector2f m_position);
player create_glutamic_acid(sf::Vector2f m_position);
player create_glutamine    (sf::Vector2f m_position);
player create_glycine      (sf::Vector2f m_position);
player create_histidine    (sf::Vector2f m_position);
player create_isoleucine   (sf::Vector2f m_position);
player create_leucine      (sf::Vector2f m_position);
player create_lysine       (sf::Vector2f m_position);
player create_methionine   (sf::Vector2f m_position);
player create_phenylalanine(sf::Vector2f m_position);
player create_proline      (sf::Vector2f m_position);
player create_serine       (sf::Vector2f m_position);
player create_threonine    (sf::Vector2f m_position);
player create_tryptophan   (sf::Vector2f m_position);
player create_tyrosine     (sf::Vector2f m_position);
player create_valine       (sf::Vector2f m_position);

void draw(
  player p,
  sf::RenderWindow &window);

void respond_to_joystick(
  player &player3,
  player &player4,
  std::vector<bullet> &bullets,
  int window_size);

void respond_to_key(
  player &player1,
  player &player2,
  std::vector<bullet> &bullets,
  int window_size);

bullet shoot(
  const player& player1,
  const int window_size);

#endif // PLAYER_H
