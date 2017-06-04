#ifndef GAME_SFML_H
#define GAME_SFML_H

/// Functions and/or classes to display the 'game' class
/// using SFML

#include <SFML/Graphics.hpp>
#include <vector>

#include "bullet.h"
#include "player.h"
#include "program_state.h"
#include "sprites_sfml.h"
#include "winner_screen_sfml.h"

class game_sfml
{
public:
  ///Starts the music
  ///@param n_players the initial number of players suggested
  game_sfml(
    sf::RenderWindow& window,
    const bool do_play_music
  );

  ///Stops the music
  ~game_sfml();

  ///Obtain the current or state after execute
  program_state get_state() const noexcept { return m_state; }

  ///Runs the battle, which is handling input and displayal.
  ///Closes when the user wants to quit
  ///or continue to winner screen when a player has won
  ///This can be obtained with the do_quit member function
  void execute();

  ///Handle input and show this screen once, to be used in testing only
  void tick();

private:
  ///Will music be played?
  bool m_do_play_music;

  ///Music played, starts at constructor, ends at destructor
  sf::Music m_music;

  ///In which state is the program while and directly after the battle?
  program_state m_state;

  ///Window used for displayal
  sf::RenderWindow& m_window;
};


void bullet_hits_player(
  std::vector<bullet> &bullets,
  std::vector<player> &ps,
  std::vector<sf::RectangleShape> &life_bars
);

std::vector<player> create_game_players(
  std::vector<amino_acid> aas,
  std::vector<sf::Vector2f> ps_pos
);

void draw_game_components(
  sf::RenderWindow &w,
  std::vector<sf::RectangleShape> life_bars,
  std::vector<sf::CircleShape> hit_ranges,
  std::vector<bullet> bullets
);

std::array<sf::Vector2f, 4> get_life_bar_positions();

std::vector<sf::Vector2f> get_start_positions();

void process_event_game(
  sf::Event event,
  sf::RenderWindow &w,
  std::vector<player> &ps,
  std::vector<bullet> &bullets,
  const int window_size
);


std::vector<sf::CircleShape> set_hit_ranges(
  std::vector<player> ps,
  std::vector<sf::Vector2f> start_positions);

std::vector<sf::RectangleShape> set_life_bars(
  int player_amount,
  std::array<sf::Vector2f, 4> life_bar_positions
);

program_state run_winner_screen(sf::RenderWindow &w,
  bool do_play_music,
  std::array<sf::RectangleShape, 4> life_bars);

#endif // GAME_SFML_H
