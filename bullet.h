#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <SFML/Graphics.hpp>

class bullet
{
public:
  bullet(
    const double damage,
    const sf::Vector2f position,
    const double speed_x,
    const double speed_y,
    const int any_window_size);

  double get_damage()         const noexcept { return m_damage  ; }
  sf::Vector2f get_position() const noexcept { return m_position; }
  double get_speed_x()        const noexcept { return m_speed_x ; }
  double get_speed_y()        const noexcept { return m_speed_y ; }
  const auto& get_sprite()    const noexcept { return m_sprite  ; }

  void move();
  void set_position(sf::Vector2f position);

private:
  double m_damage;
  sf::Vector2f m_position;
  double m_speed_x;
  double m_speed_y;
  sf::Sprite m_sprite;
  int m_window_size;
};

#endif // BULLET_H
