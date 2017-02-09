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
  start.setPosition(150,150);
  start.setColor(sf::Color::White);

  window.clear(sf::Color::Black);
  start.setString("Start Game");
  start.setCharacterSize(60);

  sf::Text two_players;
  two_players.setFont(font);
  two_players.setPosition(200,250);
  two_players.setColor(sf::Color::Magenta);
  two_players.setString("2 Players");
  two_players.setCharacterSize(50);

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
                 {press_up();}
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                 {press_down();}
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
        window.draw(two_players);
        window.draw(Amino_acid_choice);
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
void press_up()
{
    std::cout<< "Up";
}
void press_down()
{
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
