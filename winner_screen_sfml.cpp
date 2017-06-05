#include <string>

#include "game_sfml.h"
#include "winner_screen_sfml.h"

winner_screen_sfml::winner_screen_sfml(
  sf::RenderWindow& w,
  int winner,
  const bool do_play_music)
: m_do_play_music{do_play_music},
  m_menu(),
  m_state{program_state::winner},
  m_window{w},
  m_winner_text{create_winner_text(winner)}
{
}

void winner_screen_sfml::display()
{
  //Clear
  m_window.clear();
  //Text
  m_window.draw(m_winner_text);
  //Show
  m_window.display();
}

sf::Text create_winner_text(const int winner)
{
  static sf::Font font; //Text cannot be drawn if Font goes out of scope
  font.loadFromFile("arial.ttf");

  sf::Text winner_text;
  winner_text.setFont(font);
  winner_text.setPosition(sf::Vector2f(70, 225));
  #if SFML_VERSION_MINOR > 3
  winner_text.setFillColor(sf::Color::Yellow);
  #else
  winner_text.setColor(sf::Color::Yellow);
  #endif
  std::string winner_number = std::to_string(winner);
  sf::String winner_player = "Player " + winner_number + " wins!";
  winner_text.setString(winner_player);
  winner_text.setCharacterSize(75);

  return winner_text;
}

void winner_screen_sfml::execute()
{
  assert(m_state == program_state::winner);

  while (m_window.isOpen()) {
    sf::Event event;
    while(m_window.pollEvent(event))
    {
      process_event(event);
    }
    display();
    //Quit
    if (m_state == program_state::quit) return;
    //Stay here
    assert(m_state == program_state::winner);
  }
}

void winner_screen_sfml::process_event(const sf::Event& event)
{
  switch(event.type) //!OCLINT will not switch on all cases: there are too many of those
  {
    case sf::Event::Closed:
      m_state = program_state::quit;
      break;
    case sf::Event::KeyPressed:
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {
        m_state = program_state::quit;
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        m_state = program_state::quit;
      }
      break;
    default:
      break;
  }
}
