#include "bullet.h"

#include <algorithm>
#include <cassert>
#include <cmath>

bullet::bullet(
  const double damage,
  const double x,
  const double y,
  const double speed_x,
  const double speed_y
)
  : m_damage{damage},
    m_speed_x{speed_x},
    m_speed_y{speed_y},
    m_x{x},
    m_y{y}
{}

bool is_too_slow(const bullet& any_bullet)
{
  if(any_bullet.get_speed_x() < 0.5 &&
     any_bullet.get_speed_x() > -0.5 &&
     any_bullet.get_speed_y() < 0.5 &&
     any_bullet.get_speed_y() > -0.5)
  { return true; }
  return false;
}

void remove_slow_bullets(std::vector<bullet> &bullets)
{
  for(int i=0; i < static_cast<int>(bullets.size()); ++i) {
    //sf::Sprite bullet_sprite = bullets[i].get_sprite();
    if(is_too_slow(bullets[i])) {
      bullets[i] = bullets.back();
      bullets.pop_back();
      --i;
    }
  }
}

void bullet::move(const double world_size)
{
  assert(world_size > 0.0);
  //Keep m_x in [0, world_size>
  m_x = std::fmod(m_x + m_speed_x + world_size, world_size);
  //Keep m_y in [0, world_size>
  m_y = std::fmod(m_y + m_speed_y + world_size, world_size);
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
