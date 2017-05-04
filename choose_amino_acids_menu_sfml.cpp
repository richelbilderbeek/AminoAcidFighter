#include "choose_amino_acids_menu_sfml.h"

#include <cassert>
#include <SFML/Graphics/Text.hpp>
#include "game.h"
#include "menu_sfml.h"

choose_amino_acids_menu_sfml::choose_amino_acids_menu_sfml(
  sf::RenderWindow& window,
  const bool do_play_music,
  const std::vector<amino_acid> initial_amino_acids
) : m_amino_acid_texts{},
    m_center_text{},
    m_do_play_music{do_play_music},
    m_font{},
    m_menu(choose_amino_acids_menu(initial_amino_acids)),
    m_music{},
    m_player_texts(4),
    m_state{program_state::select_players},
    m_window{window}
{
  if(m_do_play_music)
  {
    play_music(m_music);
  }
  m_font.loadFromFile("arial.ttf");

  //Center text
  m_center_text.setFont(m_font);
  m_center_text.setPosition(sf::Vector2f(140, 280));
  #if SFML_VERSION_MINOR > 3
  m_center_text.setFillColor(sf::Color::White);
  #else
  m_center_text.setColor(sf::Color::White);
  #endif
  m_center_text.setCharacterSize(30);
  m_center_text.setString("Choose Your Amino Acid");

  //Player texts
  std::array<sf::Vector2f, 4> positions = get_aa_menu_text_player_positions();
  std::array<sf::Color, 4> colors = get_aa_menu_text_colors();

  for(auto i{0u}; i != m_menu.get_amino_acids().size(); ++i)
  {
    m_player_texts[i].setFont(m_font);
    m_player_texts[i].setPosition(positions[i]);
    #if SFML_VERSION_MINOR > 3
    m_player_texts[i].setFillColor(colors[i]);
    #else
    m_player_texts[i].setColor(colors[i]);
    #endif
    m_player_texts[i].setCharacterSize(35);
    m_player_texts[i].setString("Player " + std::to_string(i + 1));
  }
}

choose_amino_acids_menu_sfml::~choose_amino_acids_menu_sfml()
{
  m_music.stop();
}

void choose_amino_acids_menu_sfml::display()
{
  //Clear
  m_window.clear(sf::Color(128,128,128));

  const std::vector<sf::Text> texts = create_select_player_menu_texts(
    get_aa_menu_text_positions(),
    get_aa_menu_text_colors(),
    m_menu.get_amino_acids()
  );
  assert(texts.size() <= 4);

  //Text and amino acids
  m_window.draw(m_center_text);
  for(auto i{0u}; i != m_menu.get_amino_acids().size(); ++i)
  {
    m_window.draw(m_player_texts[i]);
    m_window.draw(texts[i]);
  }
  //Show
  m_window.display();
}

void choose_amino_acids_menu_sfml::execute()
{
  assert(m_state == program_state::select_players);

  while (1) {
    tick();
    //Quit
    if (m_state == program_state::quit) return;
    //Next screen
    if (m_state == program_state::battle) return;
    //Stay here
    assert(m_state == program_state::select_players);
  }
}

void choose_amino_acids_menu_sfml::tick()
{
  sf::Event event;
  while (m_window.pollEvent(event))
  {
    process_event(event);
    display(); //Maybe moved down?
  }
}

void choose_amino_acids_menu_sfml::process_event(const sf::Event& event)
{
  switch(event.type)
  {
    case sf::Event::Closed:
      m_state = program_state::quit;
      break;
    case sf::Event::KeyPressed:
      //battle
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        m_state = program_state::battle;
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        m_state = program_state::quit;
      }
      //player 1 and player 2
      //player 1
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
        m_menu.choose_previous(0);
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      {
        m_menu.choose_next(0);
      }
      // player 2
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      {
        m_menu.choose_previous(1);
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      {
        m_menu.choose_next(1);
      }
      break;
    case sf::Event::JoystickButtonPressed:
      //player 3 and player 4
      // player 3
      if(sf::Joystick::isButtonPressed(0, 3)) // Y button
      {
        m_menu.choose_previous(2);
      }
      if(sf::Joystick::isButtonPressed(0, 0)) // A button
      {
        m_menu.choose_next(2);
      }
      // player 4
      if(sf::Joystick::isButtonPressed(1, 3)) // Y button
      {
        m_menu.choose_previous(3);
      }
      if(sf::Joystick::isButtonPressed(1, 0)) // A button
      {
        m_menu.choose_next(3);
      }
      break;
    default:
      break;
  }
}
