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
    m_uses_power{false},
    m_x{x},
    m_y{y}
{}

void player::accelerate()
{
  //const auto angle_degrees = m_rotation_deg - 30.0;
  m_speed_x += std::cos( deg_to_rad(m_rotation_deg)) * 0.1;
  m_speed_y -= std::sin(-deg_to_rad(m_rotation_deg)) * 0.1;
}

void player::decelerate()
{
  //const auto angle_degrees = m_sprite->getRotation() - 30.0;
  m_speed_x -= std::cos( deg_to_rad(m_rotation_deg)) * 0.1;
  m_speed_y += std::sin(-deg_to_rad(m_rotation_deg)) * 0.1;
}

power get_power(const amino_acid any_aa) noexcept //!OCLINT cannot make this any shorter
{
  switch (any_aa) {
    case amino_acid::alanine:       return power::shield;
    case amino_acid::arginine:      return power::shield;
    case amino_acid::asparagine:    return power::shield;
    case amino_acid::aspartic_acid: return power::shield;
    case amino_acid::cysteine:      return power::shield;
    case amino_acid::glutamic_acid: return power::shield;
    case amino_acid::glutamine:     return power::shield;
    case amino_acid::glycine:       return power::shield;
    case amino_acid::histidine:     return power::shield;
    case amino_acid::isoleucine:    return power::shield;
    case amino_acid::leucine:       return power::shield;
    case amino_acid::lysine:        return power::shield;
    case amino_acid::methionine:    return power::shield;
    case amino_acid::phenylalanine: return power::shield;
    case amino_acid::proline:       return power::shield;
    case amino_acid::serine:        return power::shield;
    case amino_acid::threonine:     return power::shield;
    case amino_acid::tryptophan:    return power::shield;
    case amino_acid::tyrosine:      return power::shield;
    case amino_acid::valine:        return power::shield;
  }
  assert(!"Should not get here"); //!OCLINT accepted idiom
  return power::shield;
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
  auto rot_degree = any_player.get_rotation() + 10.7389;
  //10.7389 = angle from turn origin to shooter origin
  auto rot_radians = rot_degree * M_PI / 180;
  std::cout << rot_degree << std::endl;
  auto pos_x = any_player.get_x();
  auto pos_y = any_player.get_y();
  float x_shooter = pos_x + (32/std::cos(rot_radians)); //TODO
  float y_shooter = pos_y + (32*std::sin(rot_radians)); //TODO
  double angle_deg = rot_degree + 140.0;
  double angle_rad = angle_deg * M_PI / 180;
  const double speed_x{ std::sin(angle_rad) * 1.5};
  const double speed_y{-std::cos(angle_rad) * 1.5};
  return bullet(10, x_shooter, y_shooter, speed_x, speed_y);
  //return bullet(10, 10, 10, speed_x, speed_y);
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

bool player::uses_power() const
{
  return m_uses_power;
}

void player::start_using_power()
{
  m_uses_power = true;
}

void player::stops_using_power()
{
  m_uses_power = false;
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
