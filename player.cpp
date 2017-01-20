#include "player.h"

#include <iostream>

player::player(const int any_window_size)
  : m_speed_x{0.0},
    m_speed_y{0.0},
    m_sprite{},
    m_texture{},
    m_turn_speed{0.0},
    m_window_size{any_window_size}
{
  m_texture.loadFromFile("Glycine.png");
  auto x = m_texture.getSize().x;
  auto y = m_texture.getSize().y;
  //std::cout << x << ", " << y;
  //total size picture in pixels = 792;451
  //origin of molecule in pixels = 336;172
  const double x_ratio = 0.4242424;
  const double y_ratio = 0.3813747;
  m_sprite.setTexture(m_texture);
  m_sprite.setScale(sf::Vector2f(0.1, 0.1));

  m_sprite.setOrigin(sf::Vector2f(x * x_ratio, y * y_ratio));
  m_sprite.setPosition(sf::Vector2f(200, 200));
}

void player::accellerate()
{
  const auto angle_degrees = m_sprite.getRotation() - 30.0;
  const auto angle_radians = angle_degrees * M_PI / 180.0;
  m_speed_x += std::cos( angle_radians) * 0.01;
  m_speed_y -= std::sin(-angle_radians) * 0.01;
}

void player::deccellerate()
{
  const auto angle_degrees = m_sprite.getRotation() - 30.0;
  const auto angle_radians = angle_degrees * M_PI / 180.0;
  m_speed_x -= std::cos( angle_radians) * 0.01;
  m_speed_y += std::sin(-angle_radians) * 0.01;
}

void player::move()
{
  //Move
  {
    const auto x = m_sprite.getPosition().x;
    const auto y = m_sprite.getPosition().y;
    const auto new_x = std::fmod(x + m_speed_x + m_window_size, m_window_size);
    const auto new_y = std::fmod(y + m_speed_y + m_window_size, m_window_size);
    setPosition(new_x, new_y);
  }
  //Rotate
  {
    m_sprite.setRotation(m_sprite.getRotation() + m_turn_speed);

  }
}

void player::stop()
{
  m_speed_x = 0.0;
  m_speed_y = 0.0;
}

void player::turn_left()
{
  m_turn_speed -= 0.01;
  //setRotation(getRotation() - 5.0);
}

void player::turn_right()
{
  m_turn_speed += 0.01;
  //setRotation(getRotation() + 5.0);
}
