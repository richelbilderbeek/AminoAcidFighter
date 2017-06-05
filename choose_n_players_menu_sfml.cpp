#include "choose_n_players_menu_sfml.h"

#include <cassert>
#include "menu_sfml.h"

choose_n_players_menu_sfml::choose_n_players_menu_sfml(
  sf::RenderWindow& window,
  const bool do_play_music,
  const int n_players
) : m_do_play_music{do_play_music},
    m_font{},
    m_lower_text{},
    m_menu(choose_n_players_menu(n_players)),
    m_music{},
    m_state{program_state::choose_n_players},
    m_top_text{},
    m_window{window}
{
  if(m_do_play_music)
  {
    play_music(m_music);
  }
  m_font.loadFromFile("arial.ttf");

  //Top text
  m_top_text.setFont(m_font);
  m_top_text.setPosition(sf::Vector2f(75, 150));
  #if SFML_VERSION_MINOR > 3
  m_top_text.setFillColor(sf::Color::White);
  #else
  m_top_text.setColor(sf::Color::White);
  #endif
  m_top_text.setCharacterSize(60);
  m_top_text.setString("Start Game With");

  //Lower text
  m_lower_text.setFont(m_font);
  m_lower_text.setPosition(sf::Vector2f(200, 250));
  #if SFML_VERSION_MINOR > 3
  m_lower_text.setFillColor(n_players_to_color(m_menu.get_n_player()));
  #else
  m_lower_text.setColor(n_players_to_color(m_menu.get_n_player()));
  #endif
  m_lower_text.setCharacterSize(50);
}

choose_n_players_menu_sfml::~choose_n_players_menu_sfml()
{
  m_music.stop();
}

void choose_n_players_menu_sfml::display()
{
  //Clear
  m_window.clear();

  //Draw top text
  m_window.draw(m_top_text);

  //Update lower text its text and color
  const sf::String s = std::to_string(m_menu.get_n_player()) + " Players";
  m_lower_text.setString(s);
  #if SFML_VERSION_MINOR > 3
  m_lower_text.setFillColor(n_players_to_color(m_menu.get_n_player()));
  #else
  m_lower_text.setColor(n_players_to_color(m_menu.get_n_player()));
  #endif

  //Draw lower text
  m_window.draw(m_lower_text);

  //Show
  m_window.display();
}

void choose_n_players_menu_sfml::execute()
{
  assert(m_state == program_state::choose_n_players);

  while (1)
  {
    tick();
    //Quit
    if (m_state == program_state::quit) return;
    //Next screen
    if (m_state == program_state::select_players) return;
    //Stay here
    assert(m_state == program_state::choose_n_players);
  }
}

sf::Color n_players_to_color(const int player_amount)
{
  switch (player_amount)
  {
    case 2: return sf::Color::Magenta;
    case 3: return sf::Color::Yellow;
    case 4: return sf::Color::Green;
    default: break;
  }
  assert(!"Should not get here"); //!OCLINT accepted idiom
  return sf::Color::Black;
}

void choose_n_players_menu_sfml::process_event(const sf::Event& event)
{
  switch(event.type) //!OCLINT too many cases to list here
  {
    case sf::Event::Closed:
      m_state = program_state::quit;
      break;
    case sf::Event::KeyPressed:
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        m_state = program_state::quit;
      }
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
        m_menu.increase();
      }
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      {
        m_menu.decrease();
      }
      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {
        //Continue to next menu screen
        m_state = program_state::select_players;
      }
      break;
    default:
      break;
  }
}

void choose_n_players_menu_sfml::tick()
{
  sf::Event event;
  while (m_window.pollEvent(event))
  {
    process_event(event);
    display(); //Maybe moved down?
  }
}
