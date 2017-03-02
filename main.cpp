﻿#include <algorithm>
#include <cassert>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "amino_acid.h"
#include "bullet.h"
#include "menu.h"
#include "player.h"

void check_game_state(
  sf::RenderWindow &window,
  int window_size,
  int argc);

void play_game(sf::RenderWindow &window,
  const int window_size,
  amino_acid &aminoacid_player1,
  amino_acid &aminoacid_player2,
  amino_acid &aminoacid_player3,
  amino_acid &aminoacid_player4, int player_amount);

int main(int argc, char * argv[])
{  
  const int window_size = 600;

  sf::RenderWindow window(
    sf::VideoMode(window_size, window_size),
    "AminoAcidFighter",
    sf::Style::Titlebar | sf::Style::Close);

  window.setFramerateLimit(60);

  while(window.isOpen())
  {
    check_game_state(
      window,
      window_size,
      argc);
  }
}

void check_game_state(
  sf::RenderWindow &window,
  int window_size,
  int argc)
{
  bool menu_players = 1;
  bool menu_amino_acids = 0;
  bool game_screen = 0;

  int player_amount = 2;

  amino_acid aminoacid_player1 = amino_acid::alanine;
  amino_acid aminoacid_player2 = amino_acid::alanine;
  amino_acid aminoacid_player3 = amino_acid::alanine;
  amino_acid aminoacid_player4 = amino_acid::alanine;

  if(menu_players)
  {
    menu_choose_player_amount(
      window,
      menu_players,
      menu_amino_acids,
      argc,
      player_amount);
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
      aminoacid_player4,
      player_amount);
  }
  if(game_screen)
  {
    play_game(
      window,
      window_size,
      aminoacid_player1,
      aminoacid_player2,
      aminoacid_player3,
      aminoacid_player4,
      player_amount);
  }
}

void play_game(
  sf::RenderWindow &window,
  const int window_size,
  amino_acid &aminoacid_player1,
  amino_acid &aminoacid_player2,
  amino_acid &aminoacid_player3,
  amino_acid &aminoacid_player4,
  int player_amount)
{
  const sf::Vector2f start_pos_p1 { 175, 175 };
  const sf::Vector2f start_pos_p2 { 425, 175 };
  const sf::Vector2f start_pos_p3 { 175, 425 };
  const sf::Vector2f start_pos_p4 { 425, 425 };

  bool player3_joins{false};
  if(player_amount == 3)
  {
    player3_joins = true;
  }
  bool player4_joins{false};
  if(player_amount == 4)
  {
    player3_joins = true;
    player4_joins = true;
  }

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
    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
          // key support for player1 and player2
          respond_to_key(
            player1,
            player2,
            bullets,
            window_size);
          break;
        case sf::Event::JoystickButtonPressed:
          // joystick support for player3 and player4
          respond_to_joystick(
            player3,
            player4,
            bullets,
            window_size);
          break;
        default:
          break;
      }
    }

    //Move all players
    player1.move(window_size);
    player2.move(window_size);
    player3.move(window_size);
    player4.move(window_size);

    //Move all bullets
    for(auto& bullet : bullets) { bullet.move(); }

    //Remove all bullets that are out of the screen
    remove_bullets(
      bullets,
      window_size);

    window.clear(sf::Color(128,128,128));
    draw(player1, window);
    draw(player2, window);
    if(player3_joins)
    {
      draw(player3, window);
    }
    if(player4_joins)
    {
      draw(player4, window);
    }
    for(auto& bullet : bullets) { window.draw(bullet.get_sprite()); }
    window.display();
  }
}
