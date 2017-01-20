#include <cmath>
#include <iostream>
#include <vector>
#include <set>
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
  player player2(window_size);

  std::vector<bullet> bullets;

  while(window.isOpen())
  {
    sf::Event event;
    std::set<sf::Keyboard::Key> active_keys; //Keys that are pressed
    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed : active_keys.insert(event.key.code); break;
        case sf::Event::KeyReleased: active_keys.erase (event.key.code); break;
        default:
          break;
      }
    }
    //Respond to pressed keys
    if(active_keys.count(sf::Keyboard::Left))
    {
      player1.turn_left();
    }
    if(active_keys.count(sf::Keyboard::Right))
    {
      player1.turn_right();
    }
    if(active_keys.count(sf::Keyboard::Up))
    {
      player1.accellerate();
    }
    if(active_keys.count(sf::Keyboard::Down))
    {
      player1.deccellerate();
    }
    if(active_keys.count(sf::Keyboard::Space))
    {
      bullets.push_back(shoot(player1, window_size));
    }
    if(active_keys.count(sf::Keyboard::B))
    {
      player1.stop();
    }
    //Move players and object
    player1.move();
    for(auto& bullet : bullets)
    {
      bullet.move();
    }

    window.clear(sf::Color(128,128,128));
    draw(player1, window);
    for(auto& bullet : bullets)
    {
      window.draw(bullet.get_sprite());
    }
    window.display();
  }
}
