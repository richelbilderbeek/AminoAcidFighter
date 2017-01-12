#include <cmath>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "bullet.h"

int main()
{
  const int window_size = 600;

  sf::RenderWindow window(
    sf::VideoMode(window_size, window_size),
    "AminoAcidFighter",
    sf::Style::Titlebar | sf::Style::Close);

  sf::Texture glycine_texture;
  glycine_texture.loadFromFile("Glycine.png");
  auto x = glycine_texture.getSize().x;
  auto y = glycine_texture.getSize().y;
  double x_ratio = 0.4242424;
  double y_ratio = 0.3813747;
  std::cout << x << ", " << y;
  sf::Sprite glycine_sprite;
  glycine_sprite.setTexture(glycine_texture);
  glycine_sprite.setScale(sf::Vector2f(0.1, 0.1));
  glycine_sprite.setOrigin(sf::Vector2f(x * x_ratio, y * y_ratio));
  glycine_sprite.setPosition(sf::Vector2f(200, 200));

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
            auto glycine_rot = glycine_sprite.getRotation();
            glycine_rot -= 5;
            glycine_sprite.setRotation(glycine_rot);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          {
            auto glycine_rot = glycine_sprite.getRotation();
            glycine_rot += 5;
            glycine_sprite.setRotation(glycine_rot);
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          {
            auto glycine_rot_degree = glycine_sprite.getRotation() - 30;
            auto glycine_rot_radials = glycine_rot_degree * M_PI / 180;
            auto glycine_pos_x = glycine_sprite.getPosition().x;
            auto glycine_pos_y = glycine_sprite.getPosition().y;
            glycine_pos_x = glycine_pos_x + cos(glycine_rot_radials) * 5;
            glycine_pos_y = glycine_pos_y - sin(-glycine_rot_radials) * 5;
            glycine_sprite.setPosition(glycine_pos_x, glycine_pos_y);
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
          {

              auto glycine_rot_degree = glycine_sprite.getRotation() + 30;
              auto glycine_rot_radials = glycine_rot_degree * M_PI / 180;
              auto glycine_pos_x = glycine_sprite.getPosition().x;
              auto glycine_pos_y = glycine_sprite.getPosition().y;
              double x_shooter{glycine_pos_x + 450.0/10};
              double x_bullet = x_shooter + cos(glycine_rot_radials);
              double y_shooter{glycine_pos_y - 102/10};
              double y_bullet = y_shooter - sin(-glycine_rot_radials);
              std::cout << x_shooter << ", " << y_shooter;
              float bullet_x;
              sf::Vector2f position = {x_bullet, y_bullet};
              bullet bull = create_bullet(position);
              bullets.push_back(bull);
              //pewpewpew
          }
          break;
        }
        default:
          break;
      }
    }


    window.clear(sf::Color::Cyan);
    window.draw(glycine_sprite);
    for(auto& bullet : bullets)
    {
      window.draw(get_shape(bullet));
    }
    window.display();
  }
}
