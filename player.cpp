#include <cmath>
#include <cassert>
#include <iostream>
#include "helper.h"
#include "player.h"

player::player(
  amino_acid any_amino_acid,
  const double x,
  const double y
)
  :
    m_amino_acid{any_amino_acid},
    m_hp{100.0},
    m_rotation_deg{0.0},
    m_speed_x{0.0},
    m_speed_y{0.0},
    m_turn_speed_deg_per_tick{0.0},
    m_x{x},
    m_y{y}
{}

void player::accelerate()
{
  //const auto angle_degrees = m_rotation_deg - 30.0;
  m_speed_x += std::cos( deg_to_rad(m_rotation_deg)) * 0.1;
  m_speed_y -= std::sin(-deg_to_rad(m_rotation_deg)) * 0.1;
}



void player::deccellerate()
{
  //const auto angle_degrees = m_sprite->getRotation() - 30.0;
  m_speed_x -= std::cos( deg_to_rad(m_rotation_deg)) * 0.1;
  m_speed_y += std::sin(-deg_to_rad(m_rotation_deg)) * 0.1;
}



void player::move(const double world_size)
{
  assert(world_size > 0.0);
  //Keep m_x in [0, world_size>
  m_x = std::fmod(m_x + m_speed_x + world_size, world_size);
  //Keep m_y in [0, world_size>
  m_y = std::fmod(m_y + m_speed_y + world_size, world_size);
  m_rotation_deg += m_turn_speed_deg_per_tick;
}


bullet shoot(const player& any_player)
{
  auto glycine_rot_degree = any_player.get_rotation() + 10.7389;
  //10.7389 = angle from turn origin to shooter origin
  auto glycine_rot_radians = glycine_rot_degree * M_PI / 180;
  auto glycine_pos_x = any_player.get_x();
  auto glycine_pos_y = any_player.get_y();

  float x_shooter = glycine_pos_x + (std::cos(glycine_rot_radians) * 42.034985);
  float y_shooter = glycine_pos_y - (-std::sin(glycine_rot_radians) * 42.034985);
  //42.034985 = length from turn origin to shooter origin
  //std::cout << x_shooter << ", " << y_shooter << std::endl;
  double angle_deg = glycine_rot_degree + 110.0;
  double angle_rad = angle_deg * M_PI / 180;
  const double speed_x{ std::sin(angle_rad) * 1.5};
  const double speed_y{-std::cos(angle_rad) * 1.5};
  return bullet(10, x_shooter, y_shooter, speed_x, speed_y);
}

void player::stop()
{
  m_speed_x = 0.0;
  m_speed_y = 0.0;
  m_turn_speed_deg_per_tick = 0.0;
}

void player::turn_left()
{
  m_turn_speed_deg_per_tick -= 0.1;
}

void player::turn_right()
{
  m_turn_speed_deg_per_tick += 0.1;
}

void player::lose_hp()
{
  m_hp -= 0.5;
}

double get_hit_range_size()
{
  return 25.0;
}

bool operator==(const player& lhs, const player& rhs) noexcept
{
  return
       lhs.get_amino_acid() == rhs.get_amino_acid()
    && lhs.get_hp() == rhs.get_hp()
    && lhs.get_rotation() == rhs.get_rotation()
    && lhs.get_speed_x() == rhs.get_speed_x()
    && lhs.get_speed_y() == rhs.get_speed_y()
    && lhs.get_turn_speed() == rhs.get_turn_speed()
    && lhs.get_x() == rhs.get_x()
    && lhs.get_y() == rhs.get_y();
}

std::ostream& operator<<(std::ostream& os, const player& any_player) noexcept
{
  os
    << "HP: " << any_player.get_hp() << '\n'
    << "rotation (deg): " << any_player.get_rotation() << '\n'
    << "speed: " << any_player.get_speed_x() << ", " << any_player.get_speed_y() << '\n'
    << "position: " << any_player.get_x() << ", " << any_player.get_y() << '\n'
  ;
  return os;
}
