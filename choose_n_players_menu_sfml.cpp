#include "choose_n_players_menu_sfml.h"

#include <cassert>
#include "menu_sfml.h"

choose_n_players_menu_sfml::choose_n_players_menu_sfml(
  sf::RenderWindow& window,
  const bool do_play_music,
  const int n_players
) : m_do_play_music{do_play_music},
    m_menu(choose_n_players_menu(n_players)),
    m_music{},
    m_state{program_state::choose_n_players},
    m_window{window}
{
  if(m_do_play_music)
  {
    play_music(m_music);
  }
}

choose_n_players_menu_sfml::~choose_n_players_menu_sfml()
{
  m_music.stop();
}

void choose_n_players_menu_sfml::execute()
{
  while (1)
  {
    tick();
    //Quit
    if ( m_state == program_state::quit) return;
    //Next screen
    if ( m_state == program_state::select_players) return;
    //Stay here
    assert(m_state == program_state::choose_n_players);
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

void choose_n_players_menu_sfml::process_event(const sf::Event& event)
{
  switch(event.type)
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

void choose_n_players_menu_sfml::display()
{
  //Clear
  m_window.clear();

  //Text
  draw_a_text(
    "Start Game With",
    sf::Vector2f(75, 150),
    m_window,
    sf::Color::White,
    60
  );
  draw_a_text(
    std::to_string(m_menu.get_n_player()) + " Players",
    sf::Vector2f(200, 250),
    m_window,
    n_players_to_color(m_menu.get_n_player()),
    50
  );

  //Show
  m_window.display();
}

sf::Color n_players_to_color(const int player_amount)
{
  switch (player_amount)
  {
    case 2: return sf::Color::Magenta;
    case 3: return sf::Color::Yellow;
    case 4: return sf::Color::Green;
  }
  assert(!"Should not get here");
  return sf::Color::Black;
}
