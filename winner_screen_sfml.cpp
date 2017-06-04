
#include "winner_screen_sfml.h"
#include <string>

winner_screen_sfml::winner_screen_sfml(
  sf::RenderWindow& w,
  const bool do_play_music) :
  m_do_play_music{do_play_music},
  m_menu(),
  m_window{w},
  m_winner_text{}
{

}

void winner_screen_sfml::display(sf::Text winner_text)
{
  //Clear
  m_window.clear(sf::Color(128,128,128));

  //Text
  m_window.draw(winner_text);
  //Show
  m_window.display();
}

sf::Text create_winner_text(
  std::vector<sf::RectangleShape> life_bars)
{
  static sf::Font font; //Text cannot be drawn if Font goes out of scope
  font.loadFromFile("arial.ttf");

  sf::Text winner_text;
  int winner;

  for(int i = 0; i != static_cast<int>(life_bars.size()); ++i)
  {
    double size = life_bars[i].getSize().x;
    if(size > 0)
    {
      winner = i + 1;
    }
  }

  winner_text.setFont(font);
  winner_text.setPosition(sf::Vector2f(10, 10));
  #if SFML_VERSION_MINOR > 3
  winner_text.setFillColor(sf::Color::Yellow);
  #else
  winner_text.setColor(sf::Color::Yellow);
  #endif
  std::string winner_number = std::to_string(winner);
  sf::String winner_player = "Player " + winner_number + " wins!";
  winner_text.setString(winner_player);
  winner_text.setCharacterSize(35);

  return winner_text;
}

void winner_screen_sfml::execute(sf::Text winner_text)
{
  assert(m_state == program_state::winner);
  while (1) {
    display(winner_text);
    //Quit
    if (m_state == program_state::quit) return;
    //Next screen
    if (m_state == program_state::quit) return;
    //Stay here
    assert(m_state == program_state::winner);
  }
}

void winner_screen_sfml::process_event(const sf::Event& event)
{
  switch(event.type)
  {
    case sf::Event::Closed:
      m_state = program_state::quit;
      break;
    case sf::Event::KeyPressed:
      //battle
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
