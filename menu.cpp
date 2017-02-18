#include "menu.h"

void change_amino_name(
  amino_acid aminoacid_player,
  sf::Text &player_AA)
{
  if(aminoacid_player == amino_acid::alanine)
  {
     player_AA.setString("Alanine");
  }
  if(aminoacid_player == amino_acid::arginine)
  {
      player_AA.setString("Arginine");
  }
  if(aminoacid_player == amino_acid::asparagine)
  {
      player_AA.setString("Asparagine");
  }
  if(aminoacid_player == amino_acid::aspartic_acid)
  {
      player_AA.setString("Aspartic_acid");
  }
  if(aminoacid_player == amino_acid::cysteine)
  {
      player_AA.setString("Cysteine");
  }
  if(aminoacid_player == amino_acid::glutamic_acid)
  {
      player_AA.setString("Glutamic_acid");
  }
  if(aminoacid_player == amino_acid::glutamine)
  {
      player_AA.setString("Glutamine");
  }
  if(aminoacid_player == amino_acid::glycine)
  {
      player_AA.setString("Glycine");
  }
  if(aminoacid_player == amino_acid::histidine)
  {
      player_AA.setString("Histidine");
  }
  if(aminoacid_player == amino_acid::isoleucine)
  {
      player_AA.setString("Isoleucine");
  }
  if(aminoacid_player == amino_acid::leucine)
  {
      player_AA.setString("Leucine");
  }
  if(aminoacid_player == amino_acid::lysine)
  {
      player_AA.setString("Lysine");
  }
  if(aminoacid_player == amino_acid::methionine)
  {
      player_AA.setString("Methionine");
  }
  if(aminoacid_player == amino_acid::phenylalanine)
  {
      player_AA.setString("Phenylalanine");
  }
  if(aminoacid_player == amino_acid::proline)
  {
      player_AA.setString("Proline");
  }
  if(aminoacid_player == amino_acid::serine)
  {
      player_AA.setString("Serine");
  }
  if(aminoacid_player == amino_acid::threonine)
  {
      player_AA.setString("Threonine");
  }
  if(aminoacid_player == amino_acid::tryptophan)
  {
      player_AA.setString("Tryptophan");
  }
  if(aminoacid_player == amino_acid::tyrosine)
  {
      player_AA.setString("Tyrosine");
  }
  if(aminoacid_player == amino_acid::valine)
  {
      player_AA.setString("Valine");
  }
}

void press_down(
  int &player_amount)
{
    --player_amount;
    std::cout<< "Down";
}

void press_up(
  int &player_amount)
{
    ++player_amount;
    std::cout<< "Up";
}

void menu_choose_aminoacid(
  sf::RenderWindow &window,
  bool &menu_amino_acids,
  bool &game_screen,
  int argc)
{
  amino_acid aminoacid_player1 = amino_acid::alanine;
  amino_acid aminoacid_player2 = amino_acid::alanine;
  //amino_acid aminoacid_player3 = amino_acid::alanine;
  //amino_acid aminoacid_player4 = amino_acid::alanine;

  sf::Text start;
  sf::Font font;
  font.loadFromFile("arial.ttf");
  start.setFont(font);
  start.setPosition(140,280);
  start.setColor(sf::Color::White);

  window.clear(sf::Color::Black);
  start.setString("Choose Your Amino Acid");
  start.setCharacterSize(30);

  sf::Text player_one;
  player_one.setFont(font);
  player_one.setPosition(10,5);
  player_one.setColor(sf::Color::Magenta);
  player_one.setString("Player 1");
  player_one.setCharacterSize(35);
  sf::Text player_one_AA;
  player_one_AA.setFont(font);
  player_one_AA.setPosition(10,50);
  player_one_AA.setColor(sf::Color::Magenta);
  player_one_AA.setString("Alanine");
  player_one_AA.setCharacterSize(35);

  sf::Text player_two;
  player_two.setFont(font);
  player_two.setPosition(350,5);
  player_two.setColor(sf::Color::Yellow);
  player_two.setString("Player 2");
  player_two.setCharacterSize(35);
  sf::Text player_two_AA;
  player_two_AA.setFont(font);
  player_two_AA.setPosition(350,50);
  player_two_AA.setColor(sf::Color::Yellow);
  player_two_AA.setString("Alanine");
  player_two_AA.setCharacterSize(35);

  sf::Text player_three;
  player_three.setFont(font);
  player_three.setPosition(10,545);
  player_three.setColor(sf::Color::Green);
  player_three.setString("Player 3");
  player_three.setCharacterSize(35);
  sf::Text player_three_AA;
  player_three_AA.setFont(font);
  player_three_AA.setPosition(10,500);
  player_three_AA.setColor(sf::Color::Green);
  player_three_AA.setString("Leucine");
  player_three_AA.setCharacterSize(35);

  sf::Text player_four;
  player_four.setFont(font);
  player_four.setPosition(350,545);
  player_four.setColor(sf::Color::Red);
  player_four.setString("Player 4");
  player_four.setCharacterSize(35);
  sf::Text player_four_AA;
  player_four_AA.setFont(font);
  player_four_AA.setPosition(350,500);
  player_four_AA.setColor(sf::Color::Red);
  player_four_AA.setString("Valine");
  player_four_AA.setCharacterSize(35);

  sf::Text Amino_acid_choice;
  Amino_acid_choice.setFont(font);
  Amino_acid_choice.setPosition(200,350);
  Amino_acid_choice.setColor(sf::Color::Blue);
  Amino_acid_choice.setString("Glycine");
  Amino_acid_choice.setCharacterSize(50);

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
                    int player_1 = static_cast<int>(aminoacid_player1);
                    if(player_1 > 0)
                    {
                      player_1 -= 1;
                      aminoacid_player1 = static_cast<amino_acid>(player_1);
                      change_amino_name(aminoacid_player1, player_one_AA);
                    }
                 }
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                 {
                   int player_1 = static_cast<int>(aminoacid_player1);
                   if(player_1 < 19)
                   {
                     player_1 += 1;
                     aminoacid_player1 = static_cast<amino_acid>(player_1);
                     change_amino_name(aminoacid_player1, player_one_AA);
                   }
                 }
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                   {
                     int player_2 = static_cast<int>(aminoacid_player2);
                     if(player_2 < 19)
                     {
                       player_2 += 1;
                       aminoacid_player2 = static_cast<amino_acid>(player_2);
                       change_amino_name(aminoacid_player2, player_two_AA);
                     }
                   }
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                   {
                     int player_2 = static_cast<int>(aminoacid_player2);
                     if(player_2 > 0)
                     {
                       player_2 -= 1;
                       aminoacid_player2 = static_cast<amino_acid>(player_2);
                       change_amino_name(aminoacid_player2, player_two_AA);
                     }
                   }
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                 {
                   menu_amino_acids = 0;
                   game_screen = 1;
                 }
                 break;
             default: break;
            }
        }
        window.clear();
        window.draw(start);
        window.draw(player_one);
        window.draw(player_one_AA);
        window.draw(player_two);
        window.draw(player_two_AA);
        window.draw(player_three);
        window.draw(player_three_AA);
        window.draw(player_four);
        window.draw(player_four_AA);
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

  sf::Text Amino_acid_choice;
  Amino_acid_choice.setFont(font);
  Amino_acid_choice.setPosition(200,350);
  Amino_acid_choice.setColor(sf::Color::Blue);
  Amino_acid_choice.setString("Glycine");
  Amino_acid_choice.setCharacterSize(50);

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
               press_up(player_amount);
             }
           }
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
           {
             if(player_amount > 2)
             {
               press_down(player_amount);
             }
           }
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
           {}
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
           {}
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
