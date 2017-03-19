#include "bullet.h"

bullet::bullet(
  const double damage,
  const sf::Vector2f position,
  const double speed_x,
  const double speed_y,
  const int any_window_size
)
  : m_damage{damage},
    m_speed_x{speed_x},
    m_speed_y{speed_y},
    m_sprite{},
    m_window_size{any_window_size}
{
  static sf::Texture m_texture;
  m_texture.loadFromFile("Bullet.png");
  m_sprite.setTexture(m_texture);
  /// bullet is scaled to the size of arginine
  double scale = 0.12*(70.0/96.0);
  m_sprite.setScale(sf::Vector2f(scale, scale));
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

void remove_out_of_screen_bullets(
  std::vector<bullet> &bullets,
  const int window_size)
{
  for(int i=0; i < static_cast<int>(bullets.size()); ++i) {
    sf::Sprite bullet_sprite = bullets[i].get_sprite();

    if(bullet_sprite.getPosition().x < 0 ||
       bullet_sprite.getPosition().x > window_size ||
       bullet_sprite.getPosition().y < 0 ||
       bullet_sprite.getPosition().y > window_size) {
      bullets[i] = bullets.back();
      bullets.pop_back();
      --i;
    }
  }
}

void bullet::set_position(sf::Vector2f position)
{
  m_sprite.setPosition(position);
}
