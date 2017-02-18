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
    default:
      assert(!"should not get here");
  }
}

void minus_player(
  int &player_amount)
{
    --player_amount;
}

void plus_player(
  int &player_amount)
{
    ++player_amount;
}

void menu_choose_aminoacid(
  sf::RenderWindow &window,
  bool &menu_amino_acids,
  bool &game_screen,
  int argc)
{
  amino_acid aminoacid_player1 = amino_acid::alanine;
  amino_acid aminoacid_player2 = amino_acid::alanine;
  amino_acid aminoacid_player3 = amino_acid::alanine;
  amino_acid aminoacid_player4 = amino_acid::alanine;

  sf::Text start;
  sf::Font font;
  font.loadFromFile("arial.ttf");
  start.setFont(font);
  start.setPosition(140,280);
  start.setColor(sf::Color::White);

  window.clear(sf::Color::Black);
  start.setString("Choose Your Amino Acid");
  start.setCharacterSize(30);

  sf::Text player_one_text;
  player_one_text.setFont(font);
  player_one_text.setPosition(10,5);
  player_one_text.setColor(sf::Color::Magenta);
  player_one_text.setString("Player 1");
  player_one_text.setCharacterSize(35);
  sf::Text player_one_AA_text;
  player_one_AA_text.setFont(font);
  player_one_AA_text.setPosition(10,50);
  player_one_AA_text.setColor(sf::Color::Magenta);
  player_one_AA_text.setString("Alanine");
  player_one_AA_text.setCharacterSize(35);
  sf::Vector2f position_player_one_AA = sf::Vector2f(100, 175);
  player player_one_AA = create_player(aminoacid_player1, position_player_one_AA);

  sf::Text player_two_text;
  player_two_text.setFont(font);
  player_two_text.setPosition(350,5);
  player_two_text.setColor(sf::Color::Yellow);
  player_two_text.setString("Player 2");
  player_two_text.setCharacterSize(35);
  sf::Text player_two_AA_text;
  player_two_AA_text.setFont(font);
  player_two_AA_text.setPosition(350,50);
  player_two_AA_text.setColor(sf::Color::Yellow);
  player_two_AA_text.setString("Alanine");
  player_two_AA_text.setCharacterSize(35);
  sf::Vector2f position_player_two_AA = sf::Vector2f(425, 175);
  player player_two_AA = create_player(aminoacid_player2, position_player_two_AA);

  sf::Text player_three_text;
  player_three_text.setFont(font);
  player_three_text.setPosition(10,545);
  player_three_text.setColor(sf::Color::Green);
  player_three_text.setString("Player 3");
  player_three_text.setCharacterSize(35);
  sf::Text player_three_AA_text;
  player_three_AA_text.setFont(font);
  player_three_AA_text.setPosition(10,500);
  player_three_AA_text.setColor(sf::Color::Green);
  player_three_AA_text.setString("Alanine");
  player_three_AA_text.setCharacterSize(35);
  sf::Vector2f position_player_three_AA = sf::Vector2f(100, 425);
  player player_three_AA = create_player(aminoacid_player3, position_player_three_AA);

  sf::Text player_four_text;
  player_four_text.setFont(font);
  player_four_text.setPosition(350,545);
  player_four_text.setColor(sf::Color::Red);
  player_four_text.setString("Player 4");
  player_four_text.setCharacterSize(35);
  sf::Text player_four_AA_text;
  player_four_AA_text.setFont(font);
  player_four_AA_text.setPosition(350,500);
  player_four_AA_text.setColor(sf::Color::Red);
  player_four_AA_text.setString("Alanine");
  player_four_AA_text.setCharacterSize(35);
  sf::Vector2f position_player_four_AA = sf::Vector2f(425, 425);
  player player_four_AA = create_player(aminoacid_player4, position_player_four_AA);

  sf::Music game_jam;
  if (!game_jam.openFromFile("amino_acid_fighter_tune.wav"))
  {
    //error
  }
  game_jam.setPlayingOffset(sf::seconds(2));
  game_jam.setVolume(50);

  if(argc == 1)
  {
    game_jam.play();
  }

  int player_amount{2};

  while (menu_amino_acids)
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed: window.close(); break;
        case sf::Event::KeyPressed:
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          {
            change_AA_up(aminoacid_player1, player_one_AA_text, player_one_AA, position_player_one_AA);
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
          {
            change_AA_down(aminoacid_player1, player_one_AA_text, player_one_AA, position_player_one_AA);
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
          {
            change_AA_down(aminoacid_player2, player_two_AA_text, player_two_AA, position_player_two_AA);
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
          {
            change_AA_up(aminoacid_player2, player_two_AA_text, player_two_AA, position_player_two_AA);
          }
          //Go to Game
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
          {
            menu_amino_acids = 0;
            game_screen = 1;
          }
          break;
        default: break;
      }
    }

    window.clear(sf::Color(128,128,128));
    window.draw(start);
    draw(player_one_AA, window);
    window.draw(player_one_text);
    window.draw(player_one_AA_text);
    draw(player_two_AA, window);
    window.draw(player_two_text);
    window.draw(player_two_AA_text);
    draw(player_three_AA, window);
    window.draw(player_three_text);
    window.draw(player_three_AA_text);
    draw(player_four_AA, window);
    window.draw(player_four_text);
    window.draw(player_four_AA_text);
    assert(player_amount <= 4);
    //window.draw(Amino_acid_choice);
    window.display();
  }
}

void menu_choose_player_amount(
  sf::RenderWindow &window,
  bool &menu_players,
  bool &menu_amino_acids,
  int argc)
{
  sf::Text start;
  sf::Font font;
  font.loadFromFile("arial.ttf");
  start.setFont(font);
  start.setPosition(75,150);
  start.setColor(sf::Color::White);

  window.clear(sf::Color::Black);
  start.setString("Start Game With");
  start.setCharacterSize(60);

  sf::Text two_players;
  two_players.setFont(font);
  two_players.setPosition(200,250);
  two_players.setColor(sf::Color::Magenta);
  two_players.setString("2 Players");
  two_players.setCharacterSize(50);

  sf::Text three_players;
  three_players.setFont(font);
  three_players.setPosition(200,250);
  three_players.setColor(sf::Color::Yellow);
  three_players.setString("3 Players");
  three_players.setCharacterSize(50);

  sf::Text four_players;
  four_players.setFont(font);
  four_players.setPosition(200,250);
  four_players.setColor(sf::Color::Green);
  four_players.setString("4 Players");
  four_players.setCharacterSize(50);

  sf::Music game_jam;
  if (!game_jam.openFromFile("amino_acid_fighter_tune.wav"))
  {
    //error
  }
  game_jam.setPlayingOffset(sf::seconds(2));
  game_jam.setVolume(50);
  if(argc == 1)
  {
    game_jam.play();
  }

  int player_amount{2};

  while (menu_players)
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed: window.close(); break;
        case sf::Event::KeyPressed:
        {
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
          {
            if(player_amount < 4)
            {
              plus_player(player_amount);
            }
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
          {
            if(player_amount > 2)
            {
              minus_player(player_amount);
            }
          }
          //Go to AA choice menu
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
          {
            menu_players = 0;
            menu_amino_acids = 1;
          }
           default: break;
        }
      }

      window.clear();
      window.draw(start);
      if(player_amount == 2)
      {
        window.draw(two_players);
      }
      else if(player_amount == 3)
      {
        window.draw(three_players);
      }
      else if(player_amount == 4)
      {
        window.draw(four_players);
      }
      assert(player_amount <= 4);
      window.display();
    }
  }
}
