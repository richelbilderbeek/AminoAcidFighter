#include "menu_sfml.h"

#include "player_sfml.h"

void change_amino_name( //!OCLINT cannot make this any shorter
  amino_acid aminoacid_player,
  sf::Text &player_AA)
{
  switch(aminoacid_player) {
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

void change_AA_name(
  amino_acid aminoacid,
  sf::Text &AA_text
)
{
   std::string amino_name = to_str(aminoacid);
   AA_text.setString(amino_name);
   change_amino_name(aminoacid, AA_text);
}

std::vector<amino_acid> choose_aminoacids(
  sf::RenderWindow &window,
  std::vector<amino_acid> amino_acids,
  const bool play_music
)
{
  sf::Music music;
  if (!music.openFromFile("amino_acid_fighter_tune.wav")) { std::cout << "Could not find tune"; }
  music.setPlayingOffset(sf::seconds(2));
  music.setVolume(50);
  if(play_music) { music.play(); }
  sf::Font font;
  font.loadFromFile("arial.ttf");

  const std::array<sf::Vector2f, 4> text_AA_positions = get_aa_menu_text_positions    ();
  const std::array<sf::Color   , 4> text_colors       = get_aa_menu_text_colors          ();
  const std::array<sf::Vector2f, 4> text_player_pos   = get_aa_menu_text_player_positions();

  std::vector<sf::Text> AA_texts = set_AA_texts(
                                     font,
                                     text_AA_positions,
                                     text_colors,
                                     amino_acids);
  std::vector<player> players = create_menu_players(amino_acids);

  draw_players(players, window);

  program_state state = program_state::select_players;

  while (1) {
    sf::Event event;
    while (window.pollEvent(event)) {
      state = process_event_AA_choice(
        event,
        window,
        amino_acids,
        AA_texts,
        players);

      if (state == program_state::quit)
      {
        music.stop();
        return {};
      }

      if (state != program_state::select_players)
      {
        music.stop();
        return amino_acids;
      }

      //set_AA_texts(font, text_AA_positions, text_colors, AA_texts);

      //Draw everything on screen
      window.clear(sf::Color(128,128,128));
      draw_AA_choice_screen(
        window,
        players,
        text_player_pos,
        text_colors,
        AA_texts);
      window.display();
    }
  }
}

int choose_n_players(
  sf::RenderWindow &window,
  const bool do_play_music,
  int player_amount)
{
  sf::Music game_jam;
  if(do_play_music)
  {
    if (!game_jam.openFromFile("amino_acid_fighter_tune.wav"))
    {
      std::cout << "Could not find tune\n";
    }
    game_jam.setPlayingOffset(sf::seconds(2));
    game_jam.setVolume(50);
    game_jam.setLoop(true);
    game_jam.play();
  }


  program_state state = program_state::choose_n_players;

  while (1) {
    sf::Event event;
    while (window.pollEvent(event))
    {
      state = process_event_select_n_players(
        event,
        window,
        player_amount);

      if (state == program_state::quit)
      {
        game_jam.stop();
        return 0;
      }
      if (state != program_state::choose_n_players)
      {
        game_jam.stop();
        return player_amount;
      }

      sf::Vector2f player_amount_pos = sf::Vector2f(200, 250);
      const int char_size = 50;

      //Draw everything on screen
      window.clear();
      draw_a_text("Start Game With", sf::Vector2f(75, 150), window, sf::Color::White, 60);

      if(player_amount == 2) {
        draw_a_text("2 Players", player_amount_pos, window, sf::Color::Magenta, char_size);
      }
      else if(player_amount == 3) {
        draw_a_text("3 Players", player_amount_pos, window, sf::Color::Yellow, char_size);
      }
      else if(player_amount == 4) {
        draw_a_text("4 Players", player_amount_pos, window, sf::Color::Green, char_size);
      }
      assert(player_amount <= 4);

      window.display();
    }
  }
}

void choose_AA_keyboard(
  std::vector<player> &players,
  std::vector<sf::Text> &AA_texts
)
{
  // player 1
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    amino_acid aminoacid = players[0].get_amino_acid();
    aminoacid = get_prev(aminoacid);
    //std::string amino_name = to_str(aminoacid);
    //change_amino_name(aminoacid, texts[0]);
    players[0].set_amino_acid(aminoacid);
    change_AA_name(aminoacid, AA_texts[0]);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    amino_acid aminoacid = players[0].get_amino_acid();
    aminoacid = get_next(aminoacid);
    //change_amino_name(amino_acids[0], texts[0]);
    players[0].set_amino_acid(aminoacid);
    change_AA_name(aminoacid, AA_texts[0]);
  }
  // player 2
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    amino_acid aminoacid = players[1].get_amino_acid();
    aminoacid = get_prev(aminoacid);
    //std::string amino_name = to_str(aminoacid);
    //change_amino_name(aminoacid, texts[1]);
    players[1].set_amino_acid(aminoacid);
    change_AA_name(aminoacid, AA_texts[1]);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    amino_acid aminoacid = players[1].get_amino_acid();
    aminoacid = get_next(aminoacid);
    //change_amino_name(amino_acids[0], texts[0]);
    players[1].set_amino_acid(aminoacid);
    change_AA_name(aminoacid, AA_texts[1]);
  }
}

void choose_AA_joystick(
  std::vector<player> &players,
  std::vector<sf::Text> &AA_texts
)
{
  // player 3
    if(sf::Joystick::isButtonPressed(0, 3)) { // Y button
    amino_acid aminoacid = players[2].get_amino_acid();
    aminoacid = get_prev(aminoacid);
    //std::string amino_name = to_str(aminoacid);
    //change_amino_name(aminoacid, texts[1]);
    players[2].set_amino_acid(aminoacid);
    change_AA_name(aminoacid, AA_texts[2]);
  }
  if(sf::Joystick::isButtonPressed(0, 0)) { // A button
    amino_acid aminoacid = players[2].get_amino_acid();
    aminoacid = get_next(aminoacid);
    //change_amino_name(amino_acids[0], texts[0]);
    players[2].set_amino_acid(aminoacid);
    change_AA_name(aminoacid, AA_texts[2]);
  }
  // player 4
  if(sf::Joystick::isButtonPressed(1, 3)) { // Y button
    amino_acid aminoacid = players[3].get_amino_acid();
    aminoacid = get_prev(aminoacid);
    //std::string amino_name = to_str(aminoacid);
    //change_amino_name(aminoacid, texts[1]);
    players[3].set_amino_acid(aminoacid);
    change_AA_name(aminoacid, AA_texts[3]);
  }
  if(sf::Joystick::isButtonPressed(1, 0)) { // A button
    amino_acid aminoacid = players[3].get_amino_acid();
    aminoacid = get_next(aminoacid);
    //change_amino_name(amino_acids[0], texts[0]);
    players[3].set_amino_acid(aminoacid);
    change_AA_name(aminoacid, AA_texts[3]);
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
  #if SFML_VERSION_MINOR > 3
  player_text.setFillColor(color);
  #else
  player_text.setColor(color);
  #endif
  player_text.setString(text);
  player_text.setCharacterSize(size);
  window.draw(player_text);
}

void draw_AA_choice_screen(
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
  for(auto i{0u}; i != players.size(); ++i) {
    draw_a_text(
      "Player " + std::to_string(i + 1),
      text_player_pos[i],
      window,
      text_colors[i],
      char_size_player);
    draw_player(players[i], window);
    window.draw(AA_texts[i]);
  }
}

program_state process_event_AA_choice(
  sf::Event &event,
  sf::RenderWindow &window,
  std::vector<amino_acid> & /*amino_acids */,
  std::vector<sf::Text> &AA_texts,
  std::vector<player> &players)
{
  switch(event.type) {
    case sf::Event::Closed: window.close();
      return program_state::quit;
    case sf::Event::KeyPressed:
      //battle
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        return program_state::battle;
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        return program_state::quit;
      }
      //player 1 and player 2
      {
        choose_AA_keyboard(players, AA_texts);
      }
      break;
    case sf::Event::JoystickButtonPressed:
      //player 3 and player 4
      {
        choose_AA_joystick(players, AA_texts);
      }
      break;
    default:
      break;
  }
  return program_state::select_players;
}

program_state process_event_select_n_players(
  const sf::Event &event,
  sf::RenderWindow& /* window */,
  int &player_amount)
{
  switch(event.type) { //!OCLINT
    case sf::Event::Closed:
      return program_state::quit;
    case sf::Event::KeyPressed: {
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        return program_state::quit;
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
         player_amount < 4) {
        plus_player(player_amount);
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
         player_amount > 2) {
        minus_player(player_amount);
      }
      //Go to AA choice menu
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        return program_state::select_players;
      }
      break;
    }
    default:
      break;
  }
  return program_state::choose_n_players;
}

std::vector<sf::Text> set_AA_texts(
  sf::Font &font,
  std::array<sf::Vector2f, 4> text_AA_positions,
  std::array<sf::Color, 4> text_colors,
  std::vector<amino_acid> amino_acids)
{
  std::vector<sf::Text> AA_texts;
  const int n_amino_acids = amino_acids.size();

  for(auto i{0}; i != n_amino_acids; ++i) {
    sf::Text text;
    text.setFont(font);
    text.setPosition(text_AA_positions[i]);
    #if SFML_VERSION_MINOR > 3
    text.setFillColor(text_colors[i]);
    #else
    text.setColor(text_colors[i]);
    #endif
    text.setString(to_str(amino_acids[i]));
    text.setCharacterSize(35);
    AA_texts.push_back(text);
  }
  return AA_texts;
}

std::vector<player> create_menu_players(std::vector<amino_acid> amino_acids)
{
  const std::array<sf::Vector2f, 4> player_positions  = get_aa_menu_positions();

  std::vector<player> players;
  const int n_players = amino_acids.size();
  for (int i{0}; i!=n_players; ++i)
  {
    players.push_back(
      player(
        amino_acids[i],
        player_positions[i].x,
        player_positions[i].y
      )
    );
  }
  return players;
}

std::array<sf::Vector2f, 4> get_aa_menu_positions()
{
  return
  {
    sf::Vector2f(100, 200),
    sf::Vector2f(425, 200),
    sf::Vector2f(100, 425),
    sf::Vector2f(425, 425)
  };
}

std::array<sf::Vector2f, 4> get_aa_menu_text_positions()
{
  return
  {
    sf::Vector2f(10,  50),
    sf::Vector2f(350, 50),
    sf::Vector2f(10 ,500),
    sf::Vector2f(350,500)
  };
}

std::array<sf::Color, 4> get_aa_menu_text_colors()
{
  return
  {
    sf::Color::Magenta,
    sf::Color::Yellow,
    sf::Color::Green,
    sf::Color::Red
  };
}

std::array<sf::Vector2f, 4> get_aa_menu_text_player_positions()
{
  return
  {
    sf::Vector2f(10 ,   5),
    sf::Vector2f(350,   5),
    sf::Vector2f(10 , 545),
    sf::Vector2f(350, 545)
  };
}
