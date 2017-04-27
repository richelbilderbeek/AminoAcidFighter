#include "choose_amino_acids_menu_sfml.h"

#include <cassert>
#include <SFML/Graphics/Text.hpp>
#include "game.h"
#include "menu_sfml.h"

choose_amino_acids_menu_sfml::choose_amino_acids_menu_sfml(
  sf::RenderWindow& window,
  const bool do_play_music,
  const std::vector<amino_acid> initial_amino_acids
) : m_do_play_music{do_play_music},
    m_font{},
    m_menu(choose_amino_acids_menu(initial_amino_acids)),
    m_music{},
    m_state{program_state::select_players},
    m_window{window}
{
  if(m_do_play_music)
  {
    play_music(m_music);
  }
  m_font.loadFromFile("arial.ttf");
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
  draw_AA_choice_screen(
    m_window,
    create_menu_players(m_menu.get_amino_acids()),
    get_aa_menu_text_player_positions(),
    get_aa_menu_text_colors(),
    texts,
    m_font
  );

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

/*
    while (window.pollEvent(event)) {
      state = process_event_AA_choice(
        event,
        window,
        AA_texts,
        players);
*/

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
