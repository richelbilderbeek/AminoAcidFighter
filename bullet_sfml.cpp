#include "bullet_sfml.h"

sf::Sprite to_sprite(const bullet& b)
{
  static sf::Texture bullet_texture;
  bullet_texture.loadFromFile("Bullet.png");
  sf::Sprite bullet_sprite;
  bullet_sprite.setTexture(bullet_texture);
  /// bullet is scaled to the size of arginine
  double scale = 0.12*(70.0/96.0);
  bullet_sprite.setScale(sf::Vector2f(scale, scale));
  auto x = bullet_texture.getSize().x;
  auto y = bullet_texture.getSize().y;
  double ratio = 0.5;
  bullet_sprite.setOrigin(sf::Vector2f(x * ratio, y * ratio));
  bullet_sprite.setPosition(sf::Vector2f(b.get_x(), b.get_y()));
  return bullet_sprite;
}

