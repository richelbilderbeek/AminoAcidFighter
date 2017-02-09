#include "menu.h"


void open_menu()
{
  const int window_size = 600;

  sf::RenderWindow window(
    sf::VideoMode(window_size, window_size),
    "AminoAcidFighter",
    sf::Style::Titlebar | sf::Style::Close);

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
                 ; break;
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
/*
void press_key(sf::Keyboard::Key key)
{
    switch(key.event)
    {
    case sf::Keyboard::Up: press_up(); break;
    case sf::Keyboard::Down: press_down(); break;
    case sf::Keyboard::Right: press_right(); break;
    case sf::Keyboard::Left: press_left(); break;
    default: break;
    }
}
*/
void press_up(int &player_amount)
{
    ++player_amount;
    std::cout<< "Up";
}
void press_down(int &player_amount)
{
    --player_amount;
    std::cout<< "Down";
}

void press_left()
{
    std::cout<< "Left";
}
void press_right()
{
    std::cout<< "Right";
}
