#include "bullet.h"

#include <algorithm>
#include <cassert>
#include <cmath>

bullet::bullet(
  const double damage,
  const double x,
  const double y,
  const double speed_x,
  const double speed_y,
  const int n_frames_to_live
)
  : m_damage{damage},
    m_n_frames_left{n_frames_to_live},
    m_speed_x{speed_x},
    m_speed_y{speed_y},
    m_x{x},
    m_y{y}
{}

bool is_moving(const bullet& b) noexcept
{
  return b.get_speed_x() != 0.0 || b.get_speed_y() != 0.0;
}

bool is_dead(const bullet& any_bullet)
{
  return !any_bullet.is_alive();
}

void remove_dead_bullets(std::vector<bullet> &bullets)
{
  for(int i=0; i < static_cast<int>(bullets.size()); ++i)
  {
    if(is_dead(bullets[i]))
    {
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

  --m_n_frames_left;
}

void bullet::set_position(const double x, const double y)
{
  m_x = x;
  m_y = y;
}

void bullet::slow_down()
{
  m_speed_x *= 0.999;
  m_speed_y *= 0.999;
}

void stop(bullet& b) noexcept
{
  b.set_speed_x(0.0);
  b.set_speed_y(0.0);
}

std::ostream& operator<<(std::ostream& os, const bullet& b) noexcept
{
  os
    << "Speed: " << b.get_speed_x() << ',' << b.get_speed_y() << '\n'
    << "Position: " << b.get_x() << ',' << b.get_y() << '\n'
  ;
  return os;
}

bool operator==(const bullet& lhs, const bullet& rhs) noexcept
{
  return lhs.get_damage() == rhs.get_damage()
    && lhs.get_position() == rhs.get_position()
    && lhs.get_speed_x() == rhs.get_speed_x()
    && lhs.get_speed_y() == rhs.get_speed_y()
    && lhs.get_x() == rhs.get_x()
    && lhs.get_y() == rhs.get_y();
}
