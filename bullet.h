#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <vector>

class bullet
{
public:
  bullet(
    const double damage,
    const double x,
    const double y,
    const double speed_x,
    const double speed_y
  );

  auto get_damage() const noexcept { return m_damage  ; }
  std::pair<double, double> get_position() const noexcept { return { m_x, m_y }; }
  auto get_x() const noexcept { return m_x; }
  auto get_y() const noexcept { return m_y; }
  auto get_speed_x() const noexcept { return m_speed_x ; }
  auto get_speed_y() const noexcept { return m_speed_y ; }
  void set_slower_x(double x_speed) { m_speed_x = x_speed; }
  void set_slower_y(double y_speed) { m_speed_y = y_speed; }
  void set_speed_x_zero() { m_speed_x = 0.0; }
  void set_speed_y_zero() { m_speed_y = 0.0; }

  void move(const double world_size);
  void set_position(const double x, const double y);
  void set_position(const std::pair<double, double> pos) { set_position(pos.first, pos.second); }
  void slow_down();

private:
  double m_damage;
  double m_speed_x;
  double m_speed_y;
  double m_x;
  double m_y;
};

bool is_too_slow(
  const bullet& any_bullet
);

void remove_slow_bullets(std::vector<bullet> &bullets);
std::ostream& operator<<(std::ostream &os, const bullet &b) noexcept;

#endif // BULLET_H
