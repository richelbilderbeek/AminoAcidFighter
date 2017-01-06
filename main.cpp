#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
  const int window_size = 600;

  sf::RenderWindow window(
    sf::VideoMode(window_size, window_size),
    "AminoAcidFighter",
    sf::Style::Titlebar | sf::Style::Close);

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
        default:
          break;
      }
    }
    window.clear();
    window.display();
  }
}
