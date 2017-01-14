#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class bullet
{
public:
  bullet(
    const double damage,
    sf::Vector2f position,
    const double speed
  );

  double get_damage() const noexcept { return m_damage; }
  sf::Vector2f get_position() const noexcept { return m_position; }
  double get_speed() const noexcept { return m_speed; }
  const auto& get_sprite() const noexcept { return m_sprite; }

  void set_position(sf::Vector2f position);

private:
  double m_damage;
  sf::Vector2f m_position;
  sf::Sprite m_sprite;
  double m_speed;
  //sf::Texture m_texture;

};

#endif // BULLET_H
