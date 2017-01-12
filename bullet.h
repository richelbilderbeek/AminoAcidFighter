#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class bullet
{
    double m_speed;
    double m_damage;
    sf::Color m_color;
    double m_size;
    sf::Vector2f m_position;

public:
    bullet(const double speed,
           const double damage,
           sf::Color color,
           const double size,
           sf::Vector2f position);

  double get_speed() const noexcept { return m_speed; };
  double get_damage() const noexcept { return m_damage; };
  sf::Color get_color() const noexcept { return m_color; };
  double get_size() const noexcept { return m_size; };
  sf::Vector2f get_position() const noexcept { return m_position; }

  void set_position(sf::Vector2f position);
};

bullet create_bullet(sf::Vector2f position);

sf::CircleShape get_shape(const bullet& bullet);

#endif // BULLET_H
