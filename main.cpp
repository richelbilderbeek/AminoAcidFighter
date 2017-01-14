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
              auto glycine_rot_degree = player1.getRotation() + 30;
              auto glycine_rot_radials = glycine_rot_degree * M_PI / 180;
              auto glycine_pos_x = player1.getPosition().x;
              auto glycine_pos_y = player1.getPosition().y;
              double x_shooter{glycine_pos_x + 450.0/10};
              float x_bullet = x_shooter + cos(glycine_rot_radials);
              double y_shooter{glycine_pos_y - 102/10};
              float y_bullet = y_shooter - sin(-glycine_rot_radials);
              std::cout << x_shooter << ", " << y_shooter;
              sf::Vector2f position = { x_bullet, y_bullet};
              bullet bull(10.0, position, 1.0);
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
