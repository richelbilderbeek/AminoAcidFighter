#include <cassert>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "amino_acid.h"
#include "bullet.h"
#include "menu.h"
#include "player.h"

void show_game(sf::RenderWindow &window, const int window_size, amino_acid &aminoacid_player1, amino_acid &aminoacid_player2, amino_acid &aminoacid_player3, amino_acid &aminoacid_player4);

int main(int argc, char * argv[])
{  
  bool menu_players = 1;
  bool menu_amino_acids = 0;
  bool game_screen = 0;

  const int window_size = 600;

  sf::RenderWindow window(
    sf::VideoMode(window_size, window_size),
    "AminoAcidFighter",
    sf::Style::Titlebar | sf::Style::Close);

  amino_acid aminoacid_player1 = amino_acid::alanine;
  amino_acid aminoacid_player2 = amino_acid::alanine;
  amino_acid aminoacid_player3 = amino_acid::alanine;
  amino_acid aminoacid_player4 = amino_acid::alanine;
  std::vector<bullet> bullets;

  while(window.isOpen())
  {
    if(menu_players)
    {
      menu_choose_player_amount(
        window,
        menu_players,
        menu_amino_acids, argc);
    }
    if(menu_amino_acids)
    {
      menu_choose_aminoacid(
        window,
        menu_amino_acids,
        game_screen,
        argc,
        aminoacid_player1,
        aminoacid_player2,
        aminoacid_player3,
        aminoacid_player4);
    }
    if(game_screen)
    {
      show_game(
        window,
        window_size,
        aminoacid_player1,
        aminoacid_player2,
        aminoacid_player3,
        aminoacid_player4);
    }
  }
}

void show_game(
  sf::RenderWindow &window,
  const int window_size,
  amino_acid &aminoacid_player1,
  amino_acid &aminoacid_player2,
  amino_acid &aminoacid_player3,
  amino_acid &aminoacid_player4)
{
  const sf::Vector2f start_pos_p1 { 175, 175 };
  const sf::Vector2f start_pos_p2 { 425, 175 };
  const sf::Vector2f start_pos_p3 { 175, 425 };
  const sf::Vector2f start_pos_p4 { 425, 425 };

  player player1 = create_player(aminoacid_player1, start_pos_p1);
  player player2 = create_player(aminoacid_player2, start_pos_p2);
  player player3 = create_player(aminoacid_player3, start_pos_p3);
  player player4 = create_player(aminoacid_player4, start_pos_p4);

  std::vector<bullet> bullets;

  if(sf::Joystick::isConnected(0))
  {
      std::cout << "controller connected" << '\n';
  }

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
        //case sf::Event::JoystickButtonPressed: something happens ; break;
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

    //checking the buttons
    if(sf::Joystick::isButtonPressed(0, 0))
    {
        std::cout<< " 0 " << '\n';
    }
    //A button
    if(sf::Joystick::isButtonPressed(0, 1))
    {
        std::cout<< " 1 " << '\n';
    }
    //B button
    if(sf::Joystick::isButtonPressed(0, 2))
    {
        std::cout<< " 2 " << '\n';
    }
    //X button
    if(sf::Joystick::isButtonPressed(0, 3))
    {
        std::cout<< " 3 " << '\n';
    }
    //Y button
    if(sf::Joystick::isButtonPressed(0, 4))
    {
        std::cout<< " 4 " << '\n';
    }
    //LB button
    if(sf::Joystick::isButtonPressed(0, 5))
    {
        std::cout<< " 5 " << '\n';
    }
    //RB button
    if(sf::Joystick::isButtonPressed(0, 6))
    {
        std::cout<< " 6 " << '\n';
    }
    //select
    if(sf::Joystick::isButtonPressed(0, 7))
    {
        std::cout << " 7 " << '\n';
    }
    //start
    if(sf::Joystick::isButtonPressed(0, 8))
    {
        std::cout<< " 8 " << '\n';
    }
    //Xbox
    if(sf::Joystick::isButtonPressed(0, 9))
    {
        std::cout << " 9 " << '\n';
    }
    //left stick click
    if(sf::Joystick::isButtonPressed(0, 10))
    {
        std::cout<< " 10 " << '\n';
    }
    //right stick click
    if(sf::Joystick::isButtonPressed(0, 11))
    {
        std::cout << " 11 " << '\n';
    }
    if(sf::Joystick::isButtonPressed(0, 12))
    {
        std::cout<< " 12 " << '\n';
    }
    //idk

    //Move players and object
    player1.move(window_size);
    player2.move(window_size);
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
    draw(player3, window);
    draw(player4, window);
    for(auto& bullet : bullets)
    {
      window.draw(bullet.get_sprite());
    }
    window.display();
  }
}
