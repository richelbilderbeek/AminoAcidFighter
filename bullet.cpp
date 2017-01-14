#include "bullet.h"



bullet::bullet(
  const double damage,
  const sf::Vector2f position,
  const double speed)
  : m_damage{damage},
    m_position{position},
    m_speed{speed},
    m_sprite{}
    //m_texture{}
{
  static sf::Texture m_texture;
  m_texture.loadFromFile("Bullet.png");
  m_sprite.setTexture(m_texture);
  m_sprite.setScale(sf::Vector2f(0.1, 0.1));
  m_sprite.setPosition(position);

}

void bullet::set_position(sf::Vector2f position)
{
  m_position = position;
}

