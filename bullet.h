#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <vector>

class bullet
{
public:
  /// @param n_frames_to_live the number of frames a bullet lives
  bullet(
    const double damage,
    const double x,
    const double y,
    const double speed_x,
    const double speed_y,
    const int n_frames_to_live = 600
  );

  auto get_damage() const noexcept { return m_damage  ; }
  std::pair<double, double> get_position() const noexcept { return { m_x, m_y }; }
  auto get_x() const noexcept { return m_x; }
  auto get_y() const noexcept { return m_y; }
  auto get_speed_x() const noexcept { return m_speed_x ; }
  auto get_speed_y() const noexcept { return m_speed_y ; } 

  ///Is the bullet still alive?
  bool is_alive() const noexcept { return m_n_frames_left > 0; }

  ///Moves the bullet, decreases the bullet's lifetime
  void move(const double world_size);

  void set_position(const double x, const double y);
  void set_position(const std::pair<double, double> pos) { set_position(pos.first, pos.second); }

  void set_slower_x(double x_speed) { m_speed_x = x_speed; }
  void set_slower_y(double y_speed) { m_speed_y = y_speed; }
  void set_speed_x_zero() { m_speed_x = 0.0; }
  void set_speed_y_zero() { m_speed_y = 0.0; }

  ///Bullets slow down when hitting a player
  void slow_down();

private:
  double m_damage;

  ///The number of frames a bullet still lives, is incremented each call
  ///to bullet::move
  int m_n_frames_left;

  double m_speed_x;
  double m_speed_y;
  double m_x;
  double m_y;
};

bool is_dead(const bullet& any_bullet);

///Does the bullet have a non-zero delta x and delta y?
bool is_moving(const bullet& b) noexcept;

void remove_dead_bullets(std::vector<bullet> &bullets);

std::ostream& operator<<(std::ostream &os, const bullet &b) noexcept;
bool operator==(const bullet& lhs, const bullet& rhs) noexcept;

#endif // BULLET_H
