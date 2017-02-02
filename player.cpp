#include <iostream>
#include "player.h"


player::player(const int any_window_size, sf::Vector2f position, amino_acid aminoacid)
  : m_position{position},
    m_speed_x{0.0},
    m_speed_y{0.0},
    m_sprite{},
    m_texture{},
    m_turn_speed{0.0},
    m_window_size{any_window_size}
{
  switch(aminoacid)
  {
    case amino_acid::alanine:
    {
        m_texture.loadFromFile("Alanine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 744;672 (check in picture)
        //origin of molecule in pixels = 315;409 (check in picture)
        //origin is set 315/744;409/672
        const double x_ratio_origin = 315.0/744.0;
        const double y_ratio_origin = 409.0/672.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
    }
    case amino_acid::glycine:
    {
      m_texture.loadFromFile("Glycine.png");
      auto x = m_texture.getSize().x;
      auto y = m_texture.getSize().y;

      //total size picture in pixels = 792;451 (check in picture)
      //origin of molecule in pixels = 336;172 (check in picture)
      //origin is set 336/792;172/451
      const double x_ratio_origin = 336.0/792.0;
      const double y_ratio_origin = 172.0/451.0;
      m_sprite.setTexture(m_texture);
      m_sprite.setScale(sf::Vector2f(0.1, 0.1));
      m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
      m_sprite.setPosition(m_position);
      break;
    }
    default:
    {
      std::cout << "No aminoacid!!!!";
      break;
    }
  }
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


void draw(const player p, sf::RenderWindow &window)
{
  const int window_size = window.getSize().x;
  sf::Sprite s = p.get_sprite();
  //Must we draw the 'shadow' player left or right?
  const bool must_right{s.getPosition().x < window_size / 2};
  const int dx = must_right ? window_size : -window_size;
  const bool must_down{s.getPosition().y < window_size / 2};
  const int dy = must_down ? window_size : -window_size;
  //Real position
  window.draw(s);
  //Horizontal of player
  s.setPosition(s.getPosition() + sf::Vector2f(dx, 0));
  window.draw(s);
  //Down-Right of player
  s.setPosition(s.getPosition() + sf::Vector2f(0, dy));
  window.draw(s);
  //Bacl Below player
  s.setPosition(s.getPosition() + sf::Vector2f(-dx, 0));
  window.draw(s);
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

bullet shoot(const player& player1, const int window_size)
{
  auto glycine_rot_degree = player1.getRotation() + 10.7389;
  //10.7389 = angle from turn origin to shooter origin
  auto glycine_rot_radians = glycine_rot_degree * M_PI / 180;
  auto glycine_pos_x = player1.getPosition().x;
  auto glycine_pos_y = player1.getPosition().y;

  float x_shooter = glycine_pos_x + (std::cos(glycine_rot_radians) * 42.034985);
  float y_shooter = glycine_pos_y - (-std::sin(glycine_rot_radians) * 42.034985);
  //42.034985 = length from turn origin to shooter origin
  //std::cout << x_shooter << ", " << y_shooter << std::endl;
  sf::Vector2f position = { x_shooter, y_shooter};
  double angle_deg = glycine_rot_degree + 110.0;
  double angle_rad = angle_deg * M_PI / 180;
  const double speed_x{ std::sin(angle_rad) * 0.05};
  const double speed_y{-std::cos(angle_rad) * 0.05};
  return bullet(10, position, speed_x, speed_y, window_size);

}

void player::stop()
{
  m_speed_x = 0.0;
  m_speed_y = 0.0;
  m_turn_speed = 0.0;
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
