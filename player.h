#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class player
{
public:
  player();
  void accellerate();

  const auto& get_sprite() const noexcept { return sprite; }
  auto getRotation() const noexcept { return sprite.getRotation(); }
  auto getPosition() const noexcept { return sprite.getPosition(); }

  void move();
  void setPosition(const float x, const float y) noexcept { sprite.setPosition(x, y); }
  void setPosition(const sf::Vector2f p) noexcept { sprite.setPosition(p); }
  void setRotation(const float r) noexcept { sprite.setRotation(r); }
  void turn_left();
  void turn_right();

private:
  double speed_x;
  double speed_y;
  sf::Sprite sprite;
  sf::Texture texture;
};

#endif // PLAYER_H
