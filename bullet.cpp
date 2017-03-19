#include "bullet.h"

#include <algorithm>

bullet::bullet(
  const double damage,
  const double x,
  const double y,
  const double speed_x,
  const double speed_y
  //const int any_window_size
)
  : m_damage{damage},
    m_speed_x{speed_x},
    m_speed_y{speed_y},
    m_x{x},
    m_y{y}
    //m_sprite{},
    //m_window_size{any_window_size}
{
  /*
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
  */
}

bool is_out_of_screen(
  const bullet& any_bullet,
  const int window_size)
{
  if(any_bullet.get_x() < 0 ||
     any_bullet.get_x() > window_size ||
     any_bullet.get_y() < 0 ||
     any_bullet.get_y() > window_size) {
    return true;
  }
  return false;
}

void bullet::move()
{
  //sf::Vector2f p = m_sprite.getPosition();
  m_x += m_speed_x;
  m_y += m_speed_y;
  //m_sprite.setPosition(p);
}

void remove_out_of_screen_bullets(
  std::vector<bullet> &bullets,
  const int window_size)
{
  const auto new_end = std::remove_if(
    std::begin(bullets),
    std::end(bullets),
    [window_size](const bullet& b)
    {
      return is_out_of_screen(b, window_size);
    }
  );

  bullets.erase(
    new_end,
    std::end(bullets)
  );
}

void bullet::set_position(const double x, const double y)
{
  m_x = x;
  m_y = y;
}

std::ostream& operator<<(std::ostream& os, const bullet& b) noexcept
{
  os
    << "Speed: " << b.get_speed_x() << ',' << b.get_speed_y() << '\n'
    << "Position: " << b.get_x() << ',' << b.get_y() << '\n'
  ;
  return os;
}
