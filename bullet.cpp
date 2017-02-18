#include "bullet.h"

bullet::bullet(
  const double damage,
  const sf::Vector2f position,
  const double speed_x,
  const double speed_y,
  const int any_window_size
)
  : m_damage{damage},
    m_position{position},
    m_speed_x{speed_x},
    m_speed_y{speed_y},
    m_sprite{},
    m_window_size{any_window_size}
{
  static sf::Texture m_texture;
  m_texture.loadFromFile("Bullet.png");
  m_sprite.setTexture(m_texture);
  m_sprite.setScale(sf::Vector2f(0.1, 0.1));

  auto x = m_texture.getSize().x;
  auto y = m_texture.getSize().y;
  double ratio = 0.5;
  m_sprite.setOrigin(sf::Vector2f(x * ratio, y * ratio));
  m_sprite.setPosition(position);
}

void bullet::move()
{
  sf::Vector2f p = m_sprite.getPosition();
  p.x += m_speed_x;
  p.y += m_speed_y;
  m_sprite.setPosition(p);
}

void bullet::set_position(sf::Vector2f position)
{
  m_position = position;
}

