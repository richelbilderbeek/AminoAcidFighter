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

void bullet::move(const double world_size)
{
  assert(world_size > 0.0);
  //Keep m_x in [0, world_size>
  m_x = std::fmod(m_x + m_speed_x + world_size, world_size);
  //Keep m_y in [0, world_size>
  m_y = std::fmod(m_y + m_speed_y + world_size, world_size);
}

/*void remove_out_of_screen_bullets(
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
*/
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
