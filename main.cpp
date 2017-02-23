#include <cassert>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "amino_acid.h"
#include "bullet.h"
#include "menu.h"
#include "player.h"

void play_game(
  sf::RenderWindow &window,
  const int window_size,
  amino_acid &aminoacid_player1,
  amino_acid &aminoacid_player2,
  amino_acid &aminoacid_player3,
  amino_acid &aminoacid_player4);

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
      play_game(
        window,
        window_size,
        aminoacid_player1,
        aminoacid_player2,
        aminoacid_player3,
        aminoacid_player4);
    }
  }
}

void play_game(
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
        case sf::Event::KeyPressed:
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
          {
            player1.turn_left();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
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
            bullets.push_back(shoot(player1, window_size));
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
          {
            player1.stop();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
          {
            player2.accellerate();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
          {
            player2.turn_right();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
          {
            player2.deccellerate();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
          {
            player2.turn_left();
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
          {
            bullets.push_back(shoot(player2, window_size));
          }
          break;
        case sf::Event::KeyReleased: active_keys.erase (event.key.code); break;
        default:
          break;
      }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                                                                                          ///
    ///                                                                                                          ///
    ///                                                                                                          ///
    ///                                                                                                          ///
    ///                          4                                                    5                          ///
    ///                                                                                                          ///
    ///                    `.-:::::::/-`                                        `-/:::::::-.`                    ///
    ///                `.:::            //-`                                `-//            :::.`                ///
    ///              `/+/                 -/:-.                          .-:/-                 /+/`              ///
    ///             .+/                    `.-:--------------------------:-.`          --.--     /+.             ///
    ///            .:`  --.-----.--         -.`....------------------....`.           :     :     `:.            ///
    ///           `:  /             \                                                :   3   :      :`           ///
    ///          `/  :   //:-:-://:  :                  -:////:-                      :     :        /`          ///
    ///          /` /   /`       `:o  \               ./+++//+++/.              --.--  --.--  --.--  `/          ///
    ///         :. :   /           -s  :       -:::--/s+        +s/ -:::-      :     :       :     :  .:         ///
    ///        .:  |  y`     9      y  |      y     :s/          /s:     y    :   2   :     :   1   :  :.        ///
    ///        /   \   :           .s  /      y  6  /s/    8     /s/  7  y     :     :       :     :    +        ///
    ///       :.    \   :         -o  /       `////-.+s/        /s+ -////`      --.--  --.--  --.--     .:       ///
    ///      `/      :  :+:--:--:+/  :                .++/:--:/++.                    :     :            /`      ///
    ///      /`       \             /                   `-////-`    .----...----.    :   0   :           `/      ///
    ///     `/         \--.-----.--    :++////+/                  --             --   :     :             /`     ///
    ///     /`                         -:`    /`:               .:    ://////+:    :.  --.--              `/     ///
    ///     /                          -:      :.              .:   /o-       -o/   :.                     /     ///
    ///    -.                     .h---`        `--/y          /   ++           ++   /                     .-    ///
    ///    /                      /+                y          /  `y`           `y`  /                      /    ///
    ///    /                      /+                h          /  `y.    10     .y`  /                      /    ///
    ///   .-                      `y:--.        ---+s          /   :+           o:   /                      -.   ///
    ///   /                            `/     `:`               /   -+         +-   :                        /   ///
    ///   /                            /+-    +:                 :.  `.://///:.`  .:                         /   ///
    ///   /                            -://////-                  .-             -.                          /   ///
    ///   /                                                         ``---...---``                            /   ///
    ///   /                                                                                                  /   ///
    ///   /                              -..-..----..``````````````..----..-..-                              /   ///
    ///   /                           -...-.```                          ```.-...-                           /   ///
    ///   /                         ..-.``                                    ``--..                         /   ///
    ///   :                       ..-.                                            .-..                      `:   ///
    ///   `/                    .--`                                                `--.                    /`   ///
    ///    :.                 .-.`                                                    `--.                 .:    ///
    ///     :.              --.                                                          .--              .:     ///
    ///      --          /:.`                                                              `.:/          -.      ///
    ///        .---.---:.                                                                      .:---.---.        ///
    ///                                                                                                          ///
    ///                                                                                                          ///
    ///                                                                                                          ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // player 3 controls
    if(sf::Joystick::isButtonPressed(0, 0))
    {
        player3.deccellerate();
    }
    if(sf::Joystick::isButtonPressed(0, 1))
    {
        player3.turn_right();
    }
    if(sf::Joystick::isButtonPressed(0, 2))
    {
        player3.turn_left();
    }
    if(sf::Joystick::isButtonPressed(0, 3))
    {
        player3.accellerate();
    }
    if(sf::Joystick::isButtonPressed(0, 4))
    {
      bullets.push_back(shoot(player3, window_size));
    }

    //player 4
    if(sf::Joystick::isButtonPressed(1, 0))
    {
        player4.deccellerate();
    }
    if(sf::Joystick::isButtonPressed(1, 1))
    {
        player4.turn_right();
    }
    if(sf::Joystick::isButtonPressed(1, 2))
    {
        player4.turn_left();
    }
    if(sf::Joystick::isButtonPressed(1, 3))
    {
        player4.accellerate();
    }
    if(sf::Joystick::isButtonPressed(1, 4))
    {
      bullets.push_back(shoot(player4, window_size));
    }

    //Move all players and object
    player1.move(window_size);
    player2.move(window_size);
    player3.move(window_size);
    player4.move(window_size);

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
