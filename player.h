#ifndef PLAYER_H
#define PLAYER_H

#include "amino_acid.h"
#include "bullet.h"
#include <SFML/Graphics.hpp>

class player
{
public:
  player(
    const int any_window_size,
    sf::Vector2f position,
    amino_acid aminoacid);

  void accellerate();
  void deccellerate();
  auto get_rotation() const noexcept { return m_sprite.getRotation(); }
  auto get_position() const noexcept { return m_sprite.getPosition(); }
  const auto& get_sprite() const noexcept { return m_sprite; }

  void move();
  void set_position(const float x, const float y) noexcept { m_sprite.setPosition(x, y); }
  void set_position(const sf::Vector2f p) noexcept { m_sprite.setPosition(p); }
  void set_rotation(const float r) noexcept { m_sprite.setRotation(r); }
  void stop();
  void turn_left();
  void turn_right();

private:
  sf::Vector2f m_position;
  double m_speed_x;
  double m_speed_y;
  sf::Sprite m_sprite;
  sf::Texture m_texture;
  ///How fast the sprite is rotating per tick
  double m_turn_speed;
  int m_window_size;
};

void draw(player p, sf::RenderWindow &window);

bullet shoot(const player& player1, const int window_size);

#endif // PLAYER_H
