#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <SFML/Graphics.hpp>
#include "amino_acid.h"
#include "bullet.h"
#include "player.h"
#include "menu.h"

void show_game(sf::RenderWindow &window, const int window_size);
void show_menu_players(sf::RenderWindow &window);
void show_menu_amino_acids(sf::RenderWindow &window);

int main()
{
  bool menu_players = 0;
  bool menu_amino_acids = 0;
  bool game_screen = 1;

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
    if(menu_players)
    {
      show_menu_players(window);
    }
    else if(game_screen)
    {
      show_game(window, window_size);
    }
    else if(menu_amino_acids)
    {
      show_menu_amino_acids(window);
    }
  }
}


void show_game(sf::RenderWindow &window, const int window_size)
{
  sf::Vector2f start_pos_p1 { 150, 150 };
  sf::Vector2f start_pos_p2 { 400, 150 };

  amino_acid aminoacid1 = amino_acid::valine;
  amino_acid aminoacid2 = amino_acid::alanine;
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

void show_menu_players(sf::RenderWindow &window)
{
  sf::Text start;
  sf::Font font;
  font.loadFromFile("arial.ttf");
  start.setFont(font);
  start.setPosition(75,150);
  start.setColor(sf::Color::White);

  window.clear(sf::Color::Black);
  start.setString("Start Game With");
  start.setCharacterSize(60);

  sf::Text two_players;
  two_players.setFont(font);
  two_players.setPosition(200,250);
  two_players.setColor(sf::Color::Magenta);
  two_players.setString("2 Players");
  two_players.setCharacterSize(50);

  sf::Text three_players;
  three_players.setFont(font);
  three_players.setPosition(200,250);
  three_players.setColor(sf::Color::Yellow);
  three_players.setString("3 Players");
  three_players.setCharacterSize(50);

  sf::Text four_players;
  four_players.setFont(font);
  four_players.setPosition(200,250);
  four_players.setColor(sf::Color::Green);
  four_players.setString("4 Players");
  four_players.setCharacterSize(50);

  sf::Text Amino_acid_choice;
  Amino_acid_choice.setFont(font);
  Amino_acid_choice.setPosition(200,350);
  Amino_acid_choice.setColor(sf::Color::Blue);
  Amino_acid_choice.setString("Glycine");
  Amino_acid_choice.setCharacterSize(50);

   sf::Music game_jam;
   if (!game_jam.openFromFile("amino_acid_fighter_tune.wav"))
   {
     //error
   }
   game_jam.setPlayingOffset(sf::seconds(2));
   game_jam.setVolume(50);
   game_jam.play();

   int player_amount{2};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
             case sf::Event::Closed: window.close(); break;
             case sf::Event::KeyPressed:

                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                 {
                   if(player_amount < 4)
                   {
                     press_up(player_amount);
                   }
                 }
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                 {
                    if(player_amount > 2)
                      {
                        press_down(player_amount);
                      }
                 }
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                 {press_right();}
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                 {press_left();}
                 break;
             default: break;
            }
        }
        window.clear();
        window.draw(start);
        if(player_amount == 2)
        {
          window.draw(two_players);
        }
        else if(player_amount == 3)
        {
          window.draw(three_players);
        }
        else if(player_amount == 4)
        {
          window.draw(four_players);
        }
        assert(player_amount <= 4);
        //window.draw(Amino_acid_choice);
        window.display();
}
}


void show_menu_amino_acids(sf::RenderWindow &window)
{
  sf::Text start;
  sf::Font font;
  font.loadFromFile("arial.ttf");
  start.setFont(font);
  start.setPosition(140,280);
  start.setColor(sf::Color::White);

  window.clear(sf::Color::Black);
  start.setString("Choose Your Amino Acid");
  start.setCharacterSize(30);

  sf::Text player_one;
  player_one.setFont(font);
  player_one.setPosition(10,5);
  player_one.setColor(sf::Color::Magenta);
  player_one.setString("Player 1");
  player_one.setCharacterSize(50);

  sf::Text player_two;
  player_two.setFont(font);
  player_two.setPosition(400,5);
  player_two.setColor(sf::Color::Yellow);
  player_two.setString("Player 2");
  player_two.setCharacterSize(50);

  sf::Text player_three;
  player_three.setFont(font);
  player_three.setPosition(10,530);
  player_three.setColor(sf::Color::Green);
  player_three.setString("Player 3");
  player_three.setCharacterSize(50);

  sf::Text player_four;
  player_four.setFont(font);
  player_four.setPosition(400,530);
  player_four.setColor(sf::Color::Red);
  player_four.setString("Player 4");
  player_four.setCharacterSize(50);


  sf::Text Amino_acid_choice;
  Amino_acid_choice.setFont(font);
  Amino_acid_choice.setPosition(200,350);
  Amino_acid_choice.setColor(sf::Color::Blue);
  Amino_acid_choice.setString("Glycine");
  Amino_acid_choice.setCharacterSize(50);

   sf::Music game_jam;
   if (!game_jam.openFromFile("amino_acid_fighter_tune.wav"))
   {
     //error
   }
   game_jam.setPlayingOffset(sf::seconds(2));
   game_jam.setVolume(50);
   game_jam.play();

   int player_amount{2};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
             case sf::Event::Closed: window.close(); break;
             case sf::Event::KeyPressed:

                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                 {
                   if(player_amount < 4)
                   {
                     press_up(player_amount);
                   }
                 }
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                 {
                    if(player_amount > 2)
                      {
                        press_down(player_amount);
                      }
                 }
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                 {press_right();}
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                 {press_left();}
                 break;
             default: break;
            }
        }
        window.clear();
        window.draw(start);
        window.draw(player_one);
        window.draw(player_two);
        window.draw(player_three);
        window.draw(player_four);
        assert(player_amount <= 4);
        //window.draw(Amino_acid_choice);
        window.display();
}
}
