#ifndef PLAYER_H
#define PLAYER_H

#include "amino_acid.h"
#include "bullet.h"
#include "power.h"

class player
{
public:
  player(
    amino_acid any_amino_acid,
    const double x = 0.0,
    const double y = 0.0
  );

  void accelerate();
  void decelerate();
  auto get_amino_acid() const noexcept { return m_amino_acid; }
  auto get_hp() const noexcept { return m_hp; }
  std::pair<double, double> get_position() const noexcept { return { m_x, m_y }; };

  ///Return the special power of the amino acid
  auto get_rotation() const noexcept { return m_rotation_deg; }
  std::pair<double, double> get_speed() const noexcept { return { m_speed_x, m_speed_y }; };
  auto get_speed_x() const noexcept { return m_speed_x; }
  auto get_speed_y() const noexcept { return m_speed_y; }
  auto get_turn_speed() const noexcept { return m_turn_speed_deg_per_tick; }
  auto get_x()      const noexcept { return m_x; }
  auto get_y()      const noexcept { return m_y; }
  void move(const double world_size);
  void set_position(const double x, const double y) noexcept { m_x = x; m_y = y; }
  void set_rotation(const double r) noexcept { m_rotation_deg = r; }
  void stop();
  void turn_left();
  void turn_right();
  void lose_hp();

private:
  amino_acid m_amino_acid;
  double m_hp;

  /// The angle the player has, in degrees
  double m_rotation_deg;
  double m_speed_x;
  double m_speed_y;

  ///How fast the sprite is rotating per tick
  double m_turn_speed_deg_per_tick;

  double m_x;
  double m_y;

};

/// Get the radius that each player has around its center
/// in which is is hit, in pixels
double get_hit_range_size();

power get_power(const amino_acid any_amino_acid) noexcept;

///Creat a bullet shot by the player
bullet shoot(const player& any_player);

bool operator==(const player& lhs, const player& rhs) noexcept;

std::ostream& operator<<(std::ostream& os, const player& any_player) noexcept;

#endif // PLAYER_H
