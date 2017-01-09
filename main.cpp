#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
  const int window_size = 600;

  sf::RenderWindow window(
    sf::VideoMode(window_size, window_size),
    "AminoAcidFighter",
    sf::Style::Titlebar | sf::Style::Close);

  sf::Texture glycin_texture;
  glycin_texture.loadFromFile("Glycin.png");

  sf::Sprite glycin_sprite;
  glycin_sprite.setTexture(glycin_texture);
  glycin_sprite.setScale(sf::Vector2f(0.1, 0.1));
  glycin_sprite.setOrigin(sf::Vector2f(443.517, 208.489));
  glycin_sprite.setPosition(sf::Vector2f(200, 200));

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
            auto glycin_rot = glycin_sprite.getRotation();
            glycin_rot -= 5;
            glycin_sprite.setRotation(glycin_rot);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
          {
            auto glycin_rot = glycin_sprite.getRotation();
            glycin_rot += 5;
            glycin_sprite.setRotation(glycin_rot);
            auto cos_1 = cos(glycin_rot);
            auto sin_1 = sin(glycin_rot);
            std::cout << glycin_rot << ", " << cos_1 << ", " << sin_1 << std::endl;
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
          {
            auto glycin_rot_degree = glycin_sprite.getRotation();
            auto glycin_rot_radials = glycin_rot_degree * M_PI / 180;
            auto glycin_pos_x = glycin_sprite.getPosition().x;
            auto glycin_pos_y = glycin_sprite.getPosition().y;
            glycin_pos_x = glycin_pos_x + cos(-glycin_rot_radials) * 5;
            glycin_pos_y = glycin_pos_y - sin(-glycin_rot_radials) * 5;
            glycin_sprite.setPosition(glycin_pos_x, glycin_pos_y);
          }
          break;
        }
        default:
          break;
      }
    }
    window.clear(sf::Color::Cyan);
    window.draw(glycin_sprite);
    window.display();
  }
}
