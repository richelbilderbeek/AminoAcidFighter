#include "menu.h"

/*void get_menu(sf::RenderWindow window, const int window_size, const int menu_players, const int menu_amino_acids, const int game_screen)
{
  if(menu_players)
  {
    open_menu_players(window);
  }
  else if(menu_amino_acids)
  {
    open_menu_amino_acids(window);
  }
  else if(game_screen)
  {
    open_game_screen(window, window_size);
  }
}*/


/*void open_menu_players(sf::RenderWindow &window)
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
   game_jam.play();

   int player_amount{2};

while (window.isOpen())
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
                 {press_right();}
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                 {press_left();}
                 ; break;
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
        //window.draw(Amino_acid_choice);
        window.display();
    }

}*/
/*
void press_key(sf::Keyboard::Key key)
{
    switch(key.event)
    {
    case sf::Keyboard::Up: press_up(); break;
    case sf::Keyboard::Down: press_down(); break;
    case sf::Keyboard::Right: press_right(); break;
    case sf::Keyboard::Left: press_left(); break;
    default: break;
    }
}
*/
void press_up(int &player_amount)
{
    ++player_amount;
    std::cout<< "Up";
}
void press_down(int &player_amount)
{
    --player_amount;
    std::cout<< "Down";
}

void press_left()
{
    std::cout<< "Left";
}
void press_right()
{
    std::cout<< "Right";
}

/*void open_game_screen(sf::RenderWindow &window, const int window_size)
{
  sf::Vector2f start_pos_p1 { 150, 150 };
  sf::Vector2f start_pos_p2 { 400, 150 };

  amino_acid aminoacid1 = amino_acid::valine;
  amino_acid aminoacid2 = amino_acid::glycine;
  player player1(window_size, start_pos_p1, aminoacid1);
  player player2(window_size, start_pos_p2, aminoacid2);
  std::vector<bullet> bullets;

  while(window.isOpen())
  {
    if(menu_players)
    {
      open_menu_players(window);
    }
    else if(menu_amino_acids)
    {
      open_menu_amino_acids(window);
    }
    else if(game_screen)
    {
      open_game_screen(window, window_size);
    }
    sf::Event event;
    std::set<sf::Keyboard::Key> active_keys; //Keys that are pressed
    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed : active_keys.insert(event.key.code); break;
        case sf::Event::KeyReleased: active_keys.erase (event.key.code); break;
        default:
          break;
      }
    }
    //Respond to pressed keys
    if(active_keys.count(sf::Keyboard::Left))
    {
      player1.turn_left();
    }
    if(active_keys.count(sf::Keyboard::Right))
    {
      player1.turn_right();
    }
    if(active_keys.count(sf::Keyboard::Up))
    {
      player1.accellerate();
    }
    if(active_keys.count(sf::Keyboard::Down))
    {
      player1.deccellerate();
    }
    if(active_keys.count(sf::Keyboard::Space))
    {
      bullets.push_back(shoot(player1, window_size));
    }
    if(active_keys.count(sf::Keyboard::B))
    {
      player1.stop();
    }
    if(active_keys.count(sf::Keyboard::W))
    {
      player2.accellerate();
    }
    if(active_keys.count(sf::Keyboard::D))
    {
      player2.turn_right();
    }
    if(active_keys.count(sf::Keyboard::S))
    {
      player2.deccellerate();
    }
    if(active_keys.count(sf::Keyboard::A))
    {
      player2.turn_left();
    }
    if(active_keys.count(sf::Keyboard::Tab))
    {
      bullets.push_back(shoot(player2, window_size));
    }
    //Move players and object
    player1.move();
    player2.move();
    //Move all bullets
    for(auto& bullet : bullets)
    {
      bullet.move();
    }

    //Remove all bullets that are out of the screen
    for(int i=0; i < static_cast<int>(bullets.size()); ++i)
    {
      sf::Sprite bullet_sprite = bullets[i].get_sprite();

      if(bullet_sprite.getPosition().x < 0 ||
         bullet_sprite.getPosition().x > window_size ||
         bullet_sprite.getPosition().y < 0 ||
         bullet_sprite.getPosition().y > window_size)
      {
        bullets[i] = bullets.back();
        bullets.pop_back();
        --i;
      }
    }

    window.clear(sf::Color(128,128,128));
    draw(player1, window);
    draw(player2, window);
    for(auto& bullet : bullets)
    {
      window.draw(bullet.get_sprite());
    }
    window.display();
  }
}*/
