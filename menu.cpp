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
  const std::vector<amino_acid>& players)
{
  sf::Font font;
  font.loadFromFile("arial.ttf");

  bool player3{false};
  if(player_amount == 3)
  {
    player3 = true;
  }
  bool player4{false};
  if(player_amount == 4)
  {
    player3 = true;
    player4 = true;
  }

  sf::Text player1_AA_text;
  player1_AA_text.setFont(font);
  player1_AA_text.setPosition(10,50);
  player1_AA_text.setColor(sf::Color::Magenta);
  player1_AA_text.setString("Alanine");
  player1_AA_text.setCharacterSize(35);
  sf::Vector2f position_player1_AA = sf::Vector2f(100, 200);
  player player1_AA = create_player(aminoacid_player1, position_player1_AA);

  sf::Text player2_AA_text;
  player2_AA_text.setFont(font);
  player2_AA_text.setPosition(350,50);
  player2_AA_text.setColor(sf::Color::Yellow);
  player2_AA_text.setString("Alanine");
  player2_AA_text.setCharacterSize(35);
  sf::Vector2f position_player2_AA = sf::Vector2f(425, 200);
  player player2_AA = create_player(aminoacid_player2, position_player2_AA);

  sf::Text player3_AA_text;
  sf::Vector2f position_player3_AA = sf::Vector2f(100, 425);
  player3_AA_text.setFont(font);
  player3_AA_text.setPosition(10,500);
  player3_AA_text.setColor(sf::Color::Green);
  player3_AA_text.setString("Alanine");
  player3_AA_text.setCharacterSize(35);
  player player3_AA = create_player(aminoacid_player3, position_player3_AA);

  sf::Text player4_AA_text;
  sf::Vector2f position_player4_AA = sf::Vector2f(425, 425);
  player4_AA_text.setFont(font);
  player4_AA_text.setPosition(350,500);
  player4_AA_text.setColor(sf::Color::Red);
  player4_AA_text.setString("Alanine");
  player4_AA_text.setCharacterSize(35);
  player player4_AA = create_player(aminoacid_player4, position_player4_AA);

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

  while (menu_amino_acids)
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
              aminoacid_player1,
              player1_AA_text,
              player1_AA,
              position_player1_AA);
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
          {
            change_AA_down(
              aminoacid_player1,
              player1_AA_text,
              player1_AA,
              position_player1_AA);
          }
          // player 2
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
          {
            change_AA_down(
              aminoacid_player2,
              player2_AA_text,
              player2_AA,
              position_player2_AA);
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
          {
            change_AA_up(
              aminoacid_player2,
              player2_AA_text,
              player2_AA,
              position_player2_AA);
          }
          //Go to Game
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
          {
            menu_amino_acids = 0;
            game_screen = 1;
          }
        case sf::Event::JoystickButtonPressed:
          // player 3
          if(player3)
            {
            if(sf::Joystick::isButtonPressed(0, 3)) // Y button
            {
              change_AA_up(
                aminoacid_player3,
                player3_AA_text,
                player3_AA,
                position_player3_AA);
            }
            if(sf::Joystick::isButtonPressed(0, 0)) // A button
            {
              change_AA_down(
                aminoacid_player3,
                player3_AA_text,
                player3_AA,
                position_player3_AA);
            }
          }
          // player 4
          if(player4)
          {
            if(sf::Joystick::isButtonPressed(1, 3)) // Y button
            {
              change_AA_up(
                aminoacid_player4,
                player4_AA_text,
                player4_AA,
                position_player4_AA);
            }
            if(sf::Joystick::isButtonPressed(1, 0)) // A button
            {
              change_AA_down(
                aminoacid_player4,
                player4_AA_text,
                player4_AA,
                position_player4_AA);
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
    draw(player1_AA, window);
    window.draw(player1_AA_text);

    draw_text("Player 2", sf::Vector2f(350, 5)  , window, sf::Color::Yellow , char_size_player);
    draw(player2_AA, window);
    window.draw(player2_AA_text);

    if(player3)
    {
      draw_text("Player 3", sf::Vector2f(10 , 545), window, sf::Color::Green  , char_size_player);
      window.draw(player3_AA_text);
      draw(player3_AA, window);
    }

    if(player4)
    {
      draw_text("Player 4", sf::Vector2f(350, 545), window, sf::Color::Red    , char_size_player);
      window.draw(player4_AA_text);
      draw(player4_AA, window);
    }

    assert(player_amount <= 4);
    window.display();
  }
}

int menu_choose_player_amount(
  sf::RenderWindow &window,
  const int argc,
  const int player_amount)
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

  while (menu_players)
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      process_event_select_n_players(event, window, player_amount, menu_players, menu_amino_acids);

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
  game_state& state)
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
        state = game_state::select_players;
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
        const int new_size = menu_choose_player_amount(
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
        assert(!"something should happen novv, e.g. a vviner screen")
      break;
    }
  }
}

void play_game(
  sf::RenderWindow &window,
  const int window_size,
  const std::vector<amino_acid>& players
)
{
  const sf::Vector2f start_pos_p1 { 175, 175 };
  const sf::Vector2f start_pos_p2 { 425, 175 };
  const sf::Vector2f start_pos_p3 { 175, 425 };
  const sf::Vector2f start_pos_p4 { 425, 425 };

  bool player3_joins{false};
  if(player_amount == 3)
  {
    player3_joins = true;
  }
  bool player4_joins{false};
  if(player_amount == 4)
  {
    player3_joins = true;
    player4_joins = true;
  }

  player player1 = create_player(aminoacid_player1, start_pos_p1);
  player player2 = create_player(aminoacid_player2, start_pos_p2);
  player player3 = create_player(aminoacid_player3, start_pos_p3);
  player player4 = create_player(aminoacid_player4, start_pos_p4);

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

