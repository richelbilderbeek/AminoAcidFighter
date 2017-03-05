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
    case amino_acid::alanine:
    {
      player_AA.setString("Alanine");
      break;
    }
    case amino_acid::arginine:
    {
      player_AA.setString("Arginine");
      break;
    }
    case amino_acid::asparagine:
    {
      player_AA.setString("Asparagine");
      break;
    }
    case amino_acid::aspartic_acid:
    {
      player_AA.setString("Aspartic_acid");
      break;
    }
    case amino_acid::cysteine:
    {
      player_AA.setString("Cysteine");
      break;
    }
    case amino_acid::glutamic_acid:
    {
      player_AA.setString("Glutamic_acid");
      break;
    }
    case amino_acid::glutamine:
    {
      player_AA.setString("Glutamine");
      break;
    }
    case amino_acid::glycine:
    {
      player_AA.setString("Glycine");
      break;
    }
    case amino_acid::histidine:
    {
      player_AA.setString("Histidine");
      break;
    }
    case amino_acid::isoleucine:
    {
      player_AA.setString("Isoleucine");
      break;
    }
    case amino_acid::leucine:
    {
      player_AA.setString("Leucine");
      break;
    }
    case amino_acid::lysine:
    {
      player_AA.setString("Lysine");
      break;
    }
    case amino_acid::methionine:
    {
      player_AA.setString("Methionine");
      break;
    }
    case amino_acid::phenylalanine:
    {
      player_AA.setString("Phenylalanine");
      break;
    }
    case amino_acid::proline:
    {
      player_AA.setString("Proline");
      break;
    }
    case amino_acid::serine:
    {
      player_AA.setString("Serine");
      break;
    }
    case amino_acid::threonine:
    {
      player_AA.setString("Threonine");
      break;
    }
    case amino_acid::tryptophan:
    {
      player_AA.setString("Tryptophan");
      break;
    }
    case amino_acid::tyrosine:
    {
      player_AA.setString("Tyrosine");
      break;
    }
    case amino_acid::valine:
    {
      player_AA.setString("Valine");
      break;
    }
  }
}

void draw_text(
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

void minus_player(
  int &player_amount)
{
    --player_amount;
}

std::vector<amino_acid> menu_choose_aminoacid(
  sf::RenderWindow &window,
  const int argc,
  std::vector<amino_acid> amino_acids)
{
  sf::Font font;
  font.loadFromFile("arial.ttf");
  const int n_amino_acids{static_cast<int>(amino_acids.size())};
  const std::array<sf::Vector2f, 4> player_positions =
  {
      sf::Vector2f(100, 200),
      sf::Vector2f(425, 200),
      sf::Vector2f(100, 425),
      sf::Vector2f(425, 425)
  };
  std::vector<sf::Text> texts;
  {
    const std::vector<sf::Color> text_colors = { sf::Color::Magenta, sf::Color::Yellow, sf::Color::Green, sf::Color::Red };
    std::vector<sf::Vector2f> text_positions =
    {
        sf::Vector2f(10,  50),
        sf::Vector2f(350, 50),
        sf::Vector2f(10 ,500),
        sf::Vector2f(350,500)
    };
    for (int i{0}; i!=4; ++i)
    {
      sf::Text text;
      text.setFont(font);
      text.setPosition(text_positions[i]);
      text.setColor(text_colors[i]);
      text.setString(to_str(amino_acids[i]));
      text.setCharacterSize(35);
      texts.push_back(text);
    }
  }
  std::vector<player> players;
  for (int i{0}; i!=n_amino_acids; ++i)
  {
    players.push_back(create_player(amino_acids[i], player_positions[i]));
  }

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

  while (1)
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed: window.close(); break;
        case sf::Event::KeyPressed:
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
          //Go to Game
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
          {
            return amino_acids;
          }
        case sf::Event::JoystickButtonPressed:
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
          break;
        default: break;
      }
    }

    //Draw everything on screen
    window.clear(sf::Color(128,128,128));
    draw_text("Choose Your Amino Acid", sf::Vector2f(140, 280), window, sf::Color::White, 30);

    const int char_size_player = 35;
    draw_text("Player 1", sf::Vector2f(10 , 5)  , window, sf::Color::Magenta, char_size_player);
    draw(players[0], window);
    window.draw(texts[0]);

    draw_text("Player 2", sf::Vector2f(350, 5)  , window, sf::Color::Yellow , char_size_player);
    draw(players[1], window);
    window.draw(texts[1]);

    if(amino_acids.size() >= 3)
    {
      draw_text("Player 3", sf::Vector2f(10 , 545), window, sf::Color::Green  , char_size_player);
      window.draw(texts[2]);
      draw(players[2], window);
    }

    if(amino_acids.size() >= 4)
    {
      draw_text("Player 4", sf::Vector2f(350, 545), window, sf::Color::Red    , char_size_player);
      window.draw(texts[3]);
      draw(players[3], window);
    }

    window.display();
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

      sf::Vector2f player_amount_position = sf::Vector2f(200, 250);
      const int char_size = 50;

      //Draw everything on screen
      window.clear();
      draw_text("Start Game With", sf::Vector2f(75, 150), window, sf::Color::White, 60);

      if(player_amount == 2)
      {
        draw_text("2 Players", player_amount_position, window, sf::Color::Magenta, char_size);
      }
      else if(player_amount == 3)
      {
        draw_text("3 Players", player_amount_position, window, sf::Color::Yellow, char_size);
      }
      else if(player_amount == 4)
      {
        draw_text("4 Players", player_amount_position, window, sf::Color::Green, char_size);
      }
      assert(player_amount <= 4);

      window.display();
    }
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

  program_state s{program_state::choose_n_players};
  std::vector<amino_acid> players = { amino_acid::alanine, amino_acid::alanine};

  while(window.isOpen())
  {
    switch(s)
    {
      case program_state::choose_n_players:
      {
        const int new_size = choose_n_players(
          window,
          argc,
          players.size());
        s = program_state::select_players;
        players.resize(new_size); //May result in undefined behavior if size is increased
      }
      break;
      case program_state::select_players:
      {
        players = menu_choose_aminoacid(
          window,
          argc,
          players);
        s = program_state::battle;
      }
      break;
      case program_state::battle:
        play_game(
          window,
          window_size,
          players);
        assert(!"something should happen now, e.g. a winner screen");
      break;
    }
  }
}

void play_game(
  sf::RenderWindow &window,
  const int window_size,
  const std::vector<amino_acid>& amino_acids
)
{
  const sf::Vector2f start_pos_p1 { 175, 175 };
  const sf::Vector2f start_pos_p2 { 425, 175 };
  const sf::Vector2f start_pos_p3 { 175, 425 };
  const sf::Vector2f start_pos_p4 { 425, 425 };

  const bool player3_joins{amino_acids.size() >= 3};
  const bool player4_joins{amino_acids.size() >= 4};

  player player1 = create_player(amino_acids[0], start_pos_p1);
  player player2 = create_player(amino_acids[1], start_pos_p2);
  player player3 = create_player(amino_acids[2], start_pos_p3);
  player player4 = create_player(amino_acids[3], start_pos_p4);

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
            player1,
            player2,
            bullets,
            window_size);
          break;
        case sf::Event::JoystickButtonPressed:
          // joystick support for player3 and player4
          respond_to_joystick(
            player3,
            player4,
            bullets,
            window_size);
          break;
        default:
          break;
      }
    }

    //Move players and bullets
    player1.move(window_size);
    player2.move(window_size);
    player3.move(window_size);
    player4.move(window_size);
    for(auto& bullet : bullets) { bullet.move(); }

    //Remove all bullets that are out of the screen
    remove_bullets(
      bullets,
      window_size);

    window.clear(sf::Color(128,128,128));
    draw(player1, window);
    draw(player2, window);
    if(player3_joins) { draw(player3, window); }
    if(player4_joins) { draw(player4, window); }
    for(auto& bullet : bullets) { window.draw(bullet.get_sprite()); }
    window.display();
  }
}

