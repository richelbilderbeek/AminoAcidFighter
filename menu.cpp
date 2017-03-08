#include "menu.h"

void change_AA_up(
  amino_acid &aminoacid,
  sf::Text &player_AA_text,
  player &player_AA,
  sf::Vector2f position_AA)
{
  int player = static_cast<int>(aminoacid);
  if(player > 0)
  {
    player -= 1;
    aminoacid = static_cast<amino_acid>(player);
    change_amino_name(aminoacid, player_AA_text);
    player_AA = create_player(aminoacid, position_AA);
  }
}

void change_AA_down(
  amino_acid &aminoacid,
  sf::Text &player_AA_text,
  player &player_AA,
  sf::Vector2f position_AA)
{
  int player = static_cast<int>(aminoacid);
  if(player < 19)
  {
    player += 1;
    aminoacid = static_cast<amino_acid>(player);
    change_amino_name(aminoacid, player_AA_text);
    player_AA = create_player(aminoacid, position_AA);
  }
}

void change_amino_name(
  amino_acid aminoacid_player,
  sf::Text &player_AA)
{
  switch(aminoacid_player)
  {
    case amino_acid::alanine:       { player_AA.setString("Alanine"      ); break; }
    case amino_acid::arginine:      { player_AA.setString("Arginine"     ); break; }
    case amino_acid::asparagine:    { player_AA.setString("Asparagine"   ); break; }
    case amino_acid::aspartic_acid: { player_AA.setString("Aspartic_acid"); break; }
    case amino_acid::cysteine:      { player_AA.setString("Cysteine"     ); break; }
    case amino_acid::glutamic_acid: { player_AA.setString("Glutamic_acid"); break; }
    case amino_acid::glutamine:     { player_AA.setString("Glutamine"    ); break; }
    case amino_acid::glycine:       { player_AA.setString("Glycine"      ); break; }
    case amino_acid::histidine:     { player_AA.setString("Histidine"    ); break; }
    case amino_acid::isoleucine:    { player_AA.setString("Isoleucine"   ); break; }
    case amino_acid::leucine:       { player_AA.setString("Leucine"      ); break; }
    case amino_acid::lysine:        { player_AA.setString("Lysine"       ); break; }
    case amino_acid::methionine:    { player_AA.setString("Methionine"   ); break; }
    case amino_acid::phenylalanine: { player_AA.setString("Phenylalanine"); break; }
    case amino_acid::proline:       { player_AA.setString("Proline"      ); break; }
    case amino_acid::serine:        { player_AA.setString("Serine"       ); break; }
    case amino_acid::threonine:     { player_AA.setString("Threonine"    ); break; }
    case amino_acid::tryptophan:    { player_AA.setString("Tryptophan"   ); break; }
    case amino_acid::tyrosine:      { player_AA.setString("Tyrosine"     ); break; }
    case amino_acid::valine:        { player_AA.setString("Valine"       ); break; }
  }
}

int choose_n_players(
  sf::RenderWindow &window,
  const int argc,
  int player_amount)
{
  sf::Music game_jam;
  if (!game_jam.openFromFile("amino_acid_fighter_tune.wav"))
  {
    std::cout << "Could not find tune";
  }
  game_jam.setPlayingOffset(sf::seconds(2));
  game_jam.setVolume(50);
  if(argc == 1)
  {
    game_jam.play();
  }
  program_state state = program_state::choose_n_players;

  while (1)
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      process_event_select_n_players(event, window, player_amount, state);

      if (state != program_state::choose_n_players) return player_amount;

      sf::Vector2f player_amount_pos = sf::Vector2f(200, 250);
      const int char_size = 50;

      //Draw everything on screen
      window.clear();
      draw_a_text("Start Game With", sf::Vector2f(75, 150), window, sf::Color::White, 60);

      if(player_amount == 2)
      {
        draw_a_text("2 Players", player_amount_pos, window, sf::Color::Magenta, char_size);
      }
      else if(player_amount == 3)
      {
        draw_a_text("3 Players", player_amount_pos, window, sf::Color::Yellow, char_size);
      }
      else if(player_amount == 4)
      {
        draw_a_text("4 Players", player_amount_pos, window, sf::Color::Green, char_size);
      }
      assert(player_amount <= 4);

      window.display();
    }
  }
}

void choose_player_keyboard(
  std::vector<amino_acid> &amino_acids,
  std::vector<sf::Text> &texts,
  std::vector<player> &players,
  std::array<sf::Vector2f, 4> player_positions)
{
  // player 1
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    change_AA_up(
      amino_acids[0],
      texts[0],
      players[0],
      player_positions[0]);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    change_AA_down(
      amino_acids[0],
      texts[0],
      players[0],
      player_positions[0]);
  }
  // player 2
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
  {
    change_AA_down(
      amino_acids[1],
      texts[1],
      players[1],
      player_positions[1]);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
  {
    change_AA_up(
      amino_acids[1],
      texts[1],
      players[1],
      player_positions[1]);
  }
}

void choose_player_joystick(
  std::vector<amino_acid> &amino_acids,
  std::vector<sf::Text> &texts,
  std::vector<player> &players,
  std::array<sf::Vector2f, 4> player_positions)
{
  // player 3
  if(amino_acids.size() >= 3)
  {
    if(sf::Joystick::isButtonPressed(0, 3)) // Y button
    {
      change_AA_up(
        amino_acids[2],
        texts[2],
        players[2],
        player_positions[2]);
    }
    if(sf::Joystick::isButtonPressed(0, 0)) // A button
    {
      change_AA_down(
        amino_acids[2],
        texts[2],
        players[2],
        player_positions[2]);
    }
  }
  // player 4
  if(amino_acids.size() >= 4)
  {
    if(sf::Joystick::isButtonPressed(1, 3)) // Y button
    {
      change_AA_up(
        amino_acids[3],
        texts[3],
        players[3],
        player_positions[3]);
    }
    if(sf::Joystick::isButtonPressed(1, 0)) // A button
    {
      change_AA_down(
        amino_acids[3],
        texts[3],
        players[3],
        player_positions[3]);
    }
  }
}

void draw_a_text(
  std::string text,
  sf::Vector2f position,
  sf::RenderWindow &window,
  sf::Color color,
  int size)
{
  sf::Font font;
  font.loadFromFile("arial.ttf");

  sf::Text player_text;
  player_text.setFont(font);
  player_text.setPosition(position);
  player_text.setColor(color);
  player_text.setString(text);
  player_text.setCharacterSize(size);
  window.draw(player_text);
}

void draw_on_screen(
  sf::RenderWindow &window,
  std::vector<player> players,
  std::array<sf::Vector2f, 4> text_player_pos,
  std::array<sf::Color, 4> text_colors,
  std::vector<sf::Text> AA_texts)
{
  draw_a_text(
    "Choose Your Amino Acid",
    sf::Vector2f(140, 280),
    window,
    sf::Color::White,
    30);

  const int char_size_player = 35;
  for(auto i{0u}; i != players.size(); ++i)
  {
    draw_a_text(
      "Player " + std::to_string(i + 1),
      text_player_pos[i],
      window,
      text_colors[i],
      char_size_player);
    draw(players[i], window);
    window.draw(AA_texts[i]);
  }
}

std::vector<amino_acid> menu_choose_aminoacid(
  sf::RenderWindow &window,
  const int argc,
  std::vector<amino_acid> amino_acids)
{
  sf::Music game_jam;
  if (!game_jam.openFromFile("amino_acid_fighter_tune.wav"))
  {
    std::cout << "Could not find tune";
  }
  game_jam.setPlayingOffset(sf::seconds(2));
  game_jam.setVolume(50);

  sf::Font font;
  font.loadFromFile("arial.ttf");

  const std::array<sf::Vector2f, 4> player_positions  = set_player_positions     ();
  const std::array<sf::Vector2f, 4> text_AA_positions = set_text_AA_positions    ();
  const std::array<sf::Color   , 4> text_colors       = set_text_colors          ();
  const std::array<sf::Vector2f, 4> text_player_pos   = set_text_player_positions();
  std::vector<sf::Text> AA_texts = set_AA_texts(
                                     font,
                                     text_AA_positions,
                                     text_colors,
                                     amino_acids);
  std::vector<player> players    = set_players(
                                     amino_acids,
                                     player_positions);

  if(argc == 1) { game_jam.play(); }

  while (1)
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed: window.close(); break;
        case sf::Event::KeyPressed:
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { return amino_acids; }
          //player 1 and player 2
          else
          {
            choose_player_keyboard(
            amino_acids,
            AA_texts,
            players,
            player_positions);
          }
        case sf::Event::JoystickButtonPressed:
          //player 3 and player 4
          choose_player_joystick(
            amino_acids,
            AA_texts,
            players,
            player_positions);
          break;
        default: break;
      }
    }

    //Draw everything on screen
    window.clear(sf::Color(128,128,128));
    draw_on_screen(
      window,
      players,
      text_player_pos,
      text_colors,
      AA_texts);
    window.display();
  }
}

void minus_player(
  int &player_amount)
{
    --player_amount;
}

void play_game(
  sf::RenderWindow &window,
  const int window_size,
  const std::vector<amino_acid>& amino_acids
)
{
  const std::vector<sf::Vector2f> start_positions
  {
      sf::Vector2f(175, 175),
      sf::Vector2f(425, 175),
      sf::Vector2f(175, 425),
      sf::Vector2f(425, 425)
  };

  std::vector<player> players;
  for(auto i = 0u; i != amino_acids.size(); ++i)
  {
    players.push_back(create_player(amino_acids[i], start_positions[i]));
  }

  std::vector<bullet> bullets;

  if(sf::Joystick::isConnected(0))
  {
      std::cout << "controller connected" << '\n';
  }

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
        case sf::Event::KeyPressed:
          // keyboard support for player1 and player2
          respond_to_key(
            players[0],
            players[1],
            bullets,
            window_size);
          break;
        case sf::Event::JoystickButtonPressed:
          // joystick support for player3 and player4
          respond_to_joystick(
            players[2],
            players[3],
            bullets,
            window_size);
          break;
        default:
          break;
      }
    }

    //Move players and bullets
    for(auto i = 0u; i != players.size(); ++i)
    {
      players[i].move(window_size);
    }
    for(auto& bullet : bullets) { bullet.move(); }

    //Remove all bullets that are out of the screen
    remove_bullets(
      bullets,
      window_size);

    window.clear(sf::Color(128,128,128));
    for(auto i = 0u; i != players.size(); ++i)
    {
      draw(players[i], window);
    }
    for(auto& bullet : bullets) { window.draw(bullet.get_sprite()); }
    window.display();
  }
}

void plus_player(
  int &player_amount)
{
    ++player_amount;
}

void process_event_select_n_players(
  const sf::Event &event,
  sf::RenderWindow& window,
  int& player_amount,
  program_state& state)
{
  switch(event.type)
  {
    case sf::Event::Closed: window.close(); break;
    case sf::Event::KeyPressed:
    {
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
         player_amount < 4)
      {
        plus_player(player_amount);
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
         player_amount > 2)
      {
        minus_player(player_amount);
      }
      //Go to AA choice menu
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {
        state = program_state::select_players;
      }
       default:
       break;
    }
  }
}

void run(
  sf::RenderWindow &window,
  const int window_size,
  const int argc)
{

  program_state state{program_state::choose_n_players};
  std::vector<amino_acid> players = { amino_acid::alanine, amino_acid::alanine};

  while(window.isOpen())
  {
    switch(state)
    {
      case program_state::choose_n_players:
      {
        const int new_size = choose_n_players(
          window,
          argc,
          players.size());
        state = program_state::select_players;
        players.resize(new_size); //May result in undefined behavior if size is increased
      }
      break;
      case program_state::select_players:
      {
        players = menu_choose_aminoacid(
          window,
          argc,
          players);
        state = program_state::battle;
      }
      break;
      case program_state::battle:
        play_game(
          window,
          window_size,
          players);
        assert(!"something should happen now, e.g. a winner screen"); //!OCLINT need to add more screens
      break;
    }
  }
}

std::vector<sf::Text> set_AA_texts(
  sf::Font &font,
  std::array<sf::Vector2f, 4> text_AA_positions,
  std::array<sf::Color, 4> text_colors,
  std::vector<amino_acid> amino_acids)
{
  std::vector<sf::Text> AA_texts;
  const int n_amino_acids = amino_acids.size();

  for(auto i{0}; i != n_amino_acids; ++i)
  {
    sf::Text text;
    text.setFont(font);
    text.setPosition(text_AA_positions[i]);
    text.setColor(text_colors[i]);
    text.setString(to_str(amino_acids[i]));
    text.setCharacterSize(35);
    AA_texts.push_back(text);
  }
  return AA_texts;
}

std::vector<player> set_players(
  std::vector<amino_acid> amino_acids,
  std::array<sf::Vector2f, 4> player_positions)
{
  std::vector<player> players;
  const int n_amino_acids = amino_acids.size();

  for (int i{0}; i != n_amino_acids; ++i)
  {
    players.push_back(
      create_player(
        amino_acids[i],
        player_positions[i]));
  }
  return players;
}

std::array<sf::Vector2f, 4> set_player_positions()
{
  const std::array<sf::Vector2f, 4> player_positions =
  {
    sf::Vector2f(100, 200),
    sf::Vector2f(425, 200),
    sf::Vector2f(100, 425),
    sf::Vector2f(425, 425)
  };
  return player_positions;
}

std::array<sf::Vector2f, 4> set_text_AA_positions()
{
  const std::array<sf::Vector2f, 4> text_AA_positions =
  {
    sf::Vector2f(10,  50),
    sf::Vector2f(350, 50),
    sf::Vector2f(10 ,500),
    sf::Vector2f(350,500)
  };
  return text_AA_positions;
}

std::array<sf::Color, 4> set_text_colors()
{
  const std::array<sf::Color, 4> text_colors =
  {
    sf::Color::Magenta,
    sf::Color::Yellow,
    sf::Color::Green,
    sf::Color::Red
  };
  return text_colors;
}

std::array<sf::Vector2f, 4> set_text_player_positions()
{
  const std::array<sf::Vector2f, 4> text_player_pos =
  {
    sf::Vector2f(10 ,   5),
    sf::Vector2f(350,   5),
    sf::Vector2f(10 , 545),
    sf::Vector2f(350, 545)
  };
  return text_player_pos;
}
