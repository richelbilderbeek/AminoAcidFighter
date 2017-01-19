#include <cmath>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "player.h"

int main()
{
  const int window_size = 600;

  sf::RenderWindow window(
    sf::VideoMode(window_size, window_size),
    "AminoAcidFighter",
    sf::Style::Titlebar | sf::Style::Close);

  player player1(window_size);

  std::vector<bullet> bullets;

  while(window.isOpen())
  {
    sf::Event event;

    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
        {
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          {
            player1.turn_left();
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          {
            player1.turn_right();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          {
            player1.accellerate();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
          {
            player1.deccellerate();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
          {
              auto glycine_rot_degree = player1.getRotation() + 10.7389;
              //10.7389 = angle from turn origin to shooter origin
              auto glycine_rot_radians = glycine_rot_degree * M_PI / 180;
              auto glycine_pos_x = player1.getPosition().x;
              auto glycine_pos_y = player1.getPosition().y;

              float x_shooter = glycine_pos_x + (std::cos(glycine_rot_radians) * 42.034985);
              float y_shooter = glycine_pos_y - (-std::sin(glycine_rot_radians) * 42.034985);
              //42.034985 = length from turn origin to shooter origin
              std::cout << x_shooter << ", " << y_shooter << std::endl;
              sf::Vector2f position = { x_shooter, y_shooter};
              double angle_deg = glycine_rot_degree + 110.0;
              double angle_rad = angle_deg * M_PI / 180;
              const double speed_x{ std::sin(angle_rad) * 0.05};
              const double speed_y{-std::cos(angle_rad) * 0.05};
              bullet bull(10, position, speed_x, speed_y, window_size);
              bullets.push_back(bull);
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
          {
            player1.stop();
          }
          break;
        }
        default:
          break;
      }
    }
    player1.move();
    for(auto& bullet : bullets)
    {
      bullet.move();
    }

    window.clear(sf::Color(128,128,128));
    {
      sf::Sprite s = player1.get_sprite();
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
    for(auto& bullet : bullets)
    {
      window.draw(bullet.get_sprite());
    }
    window.display();
  }
}
