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
    //const int any_window_size
  );

  auto get_damage()         const noexcept { return m_damage  ; }
  auto get_x() const noexcept { return m_x; }
  auto get_y() const noexcept { return m_y; }
  auto get_speed_x()        const noexcept { return m_speed_x ; }
  auto get_speed_y()        const noexcept { return m_speed_y ; }
  //const auto& get_sprite()    const noexcept { return m_sprite  ; }

  void move();
  void set_position(const double x, const double y);

private:
  double m_damage;
  double m_speed_x;
  double m_speed_y;
  double m_x;
  double m_y;
  //sf::Sprite m_sprite;
  //int m_window_size;
};

bool is_out_of_screen(
  const bullet& any_bullet,
  const int window_size
);

void remove_out_of_screen_bullets(
  std::vector<bullet> &bullets,
  const int window_size
);

std::ostream& operator<<(std::ostream& os, const bullet& b) noexcept;

#endif // BULLET_H
