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

  void move(const double world_size);
  void set_position(const double x, const double y);
  void set_position(const std::pair<double, double> pos) { set_position(pos.first, pos.second); }

private:
  double m_damage;
  double m_speed_x;
  double m_speed_y;
  double m_x;
  double m_y;
};

bool is_out_of_screen(
  const bullet& any_bullet,
  const int window_size
);

std::ostream& operator<<(std::ostream& os, const bullet& b) noexcept;

#endif // BULLET_H
