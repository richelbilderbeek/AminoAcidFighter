#include "player.h"

#include <iostream>

player::player(const int any_window_size)
  : speed_x{0.0},
    speed_y{0.0},
    sprite{},
    texture{},
    window_size{any_window_size}
{
  texture.loadFromFile("Glycine.png");
  auto x = texture.getSize().x;
  auto y = texture.getSize().y;
  double x_ratio = 0.4242424;
  double y_ratio = 0.3813747;
  std::cout << x << ", " << y;
  sprite.setTexture(texture);
  sprite.setScale(sf::Vector2f(0.1, 0.1));

  sprite.setOrigin(sf::Vector2f(x * x_ratio, y * y_ratio));
  sprite.setPosition(sf::Vector2f(200, 200));
}

void player::accellerate()
{
  const auto angle_degrees = sprite.getRotation() - 30.0;
  const auto angle_radians = angle_degrees * M_PI / 180.0;
  speed_x += std::cos( angle_radians) * 0.01;
  speed_y -= std::sin(-angle_radians) * 0.01;
}

void player::deccellerate()
{
  const auto angle_degrees = sprite.getRotation() - 30.0;
  const auto angle_radians = angle_degrees * M_PI / 180.0;
  speed_x -= std::cos( angle_radians) * 0.01;
  speed_y += std::sin(-angle_radians) * 0.01;
}

void player::move()
{
  const auto x = sprite.getPosition().x;
  const auto y = sprite.getPosition().y;
  const auto new_x = std::fmod(x + speed_x + window_size, window_size);
  const auto new_y = std::fmod(y + speed_y + window_size, window_size);
  setPosition(new_x, new_y);
}

void player::stop()
{
  speed_x = 0.0;
  speed_y = 0.0;
}

void player::turn_left()
{
  setRotation(getRotation() - 5.0);
}

void player::turn_right()
{
  setRotation(getRotation() + 5.0);
}
