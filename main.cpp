#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <SFML/Graphics.hpp>
#include "amino_acid.h"
#include "bullet.h"
#include "player.h"

int main()
{
  const int window_size = 600;

  sf::RenderWindow window(
    sf::VideoMode(window_size, window_size),
    "AminoAcidFighter",
    sf::Style::Titlebar | sf::Style::Close);

  sf::Vector2f start_pos_p1 { 150, 150 };
  sf::Vector2f start_pos_p2 { 400, 150 };

  amino_acid aminoacid1 = amino_acid::valine;
  amino_acid aminoacid2 = amino_acid::glycine;
  player player1(window_size, start_pos_p1, aminoacid1);
  player player2(window_size, start_pos_p2, aminoacid2);
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
    if(active_keys.count(sf::Keyboard::W))
    {
      player2.accellerate();
    }
    if(active_keys.count(sf::Keyboard::D))
    {
      player2.turn_right();
    }
    if(active_keys.count(sf::Keyboard::S))
    {
      player2.deccellerate();
    }
    if(active_keys.count(sf::Keyboard::A))
    {
      player2.turn_left();
    }
    if(active_keys.count(sf::Keyboard::Tab))
    {
      bullets.push_back(shoot(player2, window_size));
    }
    //Move players and object
    player1.move();
    player2.move();
    //Move all bullets
    for(auto& bullet : bullets)
    {
      bullet.move();
    }

    //Remove all bullets that are out of the screen
    for(int i=0; i < static_cast<int>(bullets.size()); ++i)
    {
      sf::Sprite bullet_sprite = bullets[i].get_sprite();

      if(bullet_sprite.getPosition().x < 0 ||
         bullet_sprite.getPosition().x > window_size ||
         bullet_sprite.getPosition().y < 0 ||
         bullet_sprite.getPosition().y > window_size)
      {
        bullets[i] = bullets.back();
        bullets.pop_back();
        --i;
      }
    }

    window.clear(sf::Color(128,128,128));
    draw(player1, window);
    draw(player2, window);
    for(auto& bullet : bullets)
    {
      window.draw(bullet.get_sprite());
    }
    window.display();
  }
}
