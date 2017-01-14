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

  player glycine_sprite;

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
            glycine_sprite.turn_left();
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          {
            glycine_sprite.turn_right();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          {
            glycine_sprite.accellerate();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
          {

              auto glycine_rot_degree = glycine_sprite.getRotation() + 30;
              auto glycine_rot_radials = glycine_rot_degree * M_PI / 180;
              auto glycine_pos_x = glycine_sprite.getPosition().x;
              auto glycine_pos_y = glycine_sprite.getPosition().y;
              double x_shooter{glycine_pos_x + 450.0/10};
              float x_bullet = x_shooter + cos(glycine_rot_radials);
              double y_shooter{glycine_pos_y - 102/10};
              float y_bullet = y_shooter - sin(-glycine_rot_radials);
              std::cout << x_shooter << ", " << y_shooter;
              sf::Vector2f position = { x_bullet, y_bullet};
              bullet bull = create_bullet(position);
              bullets.push_back(bull);
          }
          break;
        }
        default:
          break;
      }
    }
    glycine_sprite.move();

    window.clear(sf::Color::Cyan);
    window.draw(glycine_sprite.get_sprite());
    for(auto& bullet : bullets)
    {
      window.draw(get_shape(bullet));
    }
    window.display();
  }
}
