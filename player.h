#ifndef PLAYER_H
#define PLAYER_H

#include <cmath>
#include <SFML/Graphics.hpp>
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
  std::pair<double, double> get_position() const noexcept { return { m_x, m_y }; }

  ///Return the special power of the amino acid
  auto get_rotation() const noexcept { return m_rotation_deg; }
  auto get_shoot_ability() const noexcept { return m_able_to_shoot; }
  std::pair<double, double> get_speed() const noexcept { return { m_speed_x, m_speed_y }; }
  auto get_speed_x() const noexcept { return m_speed_x; }
  auto get_speed_y() const noexcept { return m_speed_y; }
  auto get_turn_speed() const noexcept { return m_turn_speed_deg_per_tick; }
  auto get_x() const noexcept { return m_x; }
  auto get_y() const noexcept { return m_y; }
  void move(const double world_size);
  void set_amino_acid(const amino_acid aminoacid) { m_amino_acid = aminoacid; };
  void set_position(const double x, const double y) noexcept { m_x = x; m_y = y; }
  void set_rotation(const double r) noexcept { m_rotation_deg = r; }
  void set_speed_x(double speed) { m_speed_x = speed; }
  void set_speed_y(double speed) { m_speed_y = speed; }

  void stop();

  ///When a player starts using a power, the game logic 'game' may be modified
  void start_using_power(game& g);

  ///When a player its power ends, the game logic 'game' may be modified
  void stops_using_power(game& g);

  void turn_left();
  void turn_right();
  void lose_hp();
  void unable_to_shoot() { m_able_to_shoot = false; }
  bool uses_power() const;

private:
  bool m_able_to_shoot;
  amino_acid m_amino_acid;
  double m_hp;

  /// The angle the player has, in degrees
  double m_rotation_deg;
  double m_speed_x;
  double m_speed_y;

  ///How fast the sprite is rotating per tick
  double m_turn_speed_deg_per_tick;

  bool m_uses_power;

  double m_x;
  double m_y;

};

void do_power(power any_power, game& g);

/// Get the radius that each player has around its center
/// in which is is hit, in pixels
double get_hit_range_size();

power get_power(const amino_acid any_aa) noexcept;

///Creat a bullet shot by the player
bullet shoot(const player& any_player);

bool operator==(const player& lhs, const player& rhs) noexcept;

std::ostream& operator<<(std::ostream& os, const player& any_player) noexcept;

#endif // PLAYER_H
