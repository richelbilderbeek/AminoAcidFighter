#include "player_sfml.h"

#include <cassert>
#include "sprites_sfml.h"

void draw_player( //!OCLINT cannot make this any shorter
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  switch(p.get_amino_acid()) {
    case amino_acid::alanine:       return draw_alanine      (p, w, sprites);
    case amino_acid::arginine:      return draw_arginine     (p, w, sprites);
    case amino_acid::asparagine:    return draw_asparagine   (p, w, sprites);
    case amino_acid::aspartic_acid: return draw_aspartic_acid(p, w, sprites);
    case amino_acid::cysteine:      return draw_cysteine     (p, w, sprites);
    case amino_acid::glutamic_acid: return draw_glutamic_acid(p, w, sprites);
    case amino_acid::glutamine:     return draw_glutamine    (p, w, sprites);
    case amino_acid::glycine:       return draw_glycine      (p, w, sprites);
    case amino_acid::histidine:     return draw_histidine    (p, w, sprites);
    case amino_acid::isoleucine:    return draw_isoleucine   (p, w, sprites);
    case amino_acid::leucine:       return draw_leucine      (p, w, sprites);
    case amino_acid::lysine:        return draw_lysine       (p, w, sprites);
    case amino_acid::methionine:    return draw_methionine   (p, w, sprites);
    case amino_acid::phenylalanine: return draw_phenylalanine(p, w, sprites);
    case amino_acid::proline:       return draw_proline      (p, w, sprites);
    case amino_acid::serine:        return draw_serine       (p, w, sprites);
    case amino_acid::threonine:     return draw_threonine    (p, w, sprites);
    case amino_acid::tryptophan:    return draw_tryptophan   (p, w, sprites);
    case amino_acid::tyrosine:      return draw_tyrosine     (p, w, sprites);
    case amino_acid::valine:        return draw_valine       (p, w, sprites);
  }
  assert(!"should not get here"); //!OCLINT accepted idiom
}

void draw_players(
  std::vector<player>& ps,
  sf::RenderWindow &w,
  Sprites_sfml& sprites)
{
  for(int i{0}; i < static_cast<int>(ps.size()); ++i)
  {
    if(ps[i].get_hp() <= 0) continue;
    const int window_size = w.getSize().x;
    //Must we draw the 'shadow' player left or right?
    const bool must_right{ps[i].get_x() < window_size / 2};
    const int dx = must_right ? window_size : -window_size;
    const bool must_down{ps[i].get_y() < window_size / 2};
    const int dy = must_down ? window_size : -window_size;
    //Real position
    draw_player(ps[i], w, sprites);
    //Horizontal of player
    ps[i].set_position(ps[i].get_x() + dx, ps[i].get_y());
    draw_player(ps[i], w, sprites);
    //Down-Right of player
    ps[i].set_position(ps[i].get_x(), ps[i].get_y() +  dy);
    draw_player(ps[i], w, sprites);
    //Bacl Below player
    ps[i].set_position(ps[i].get_x() - dx, ps[i].get_y());
    draw_player(ps[i], w, sprites);
  }
}

/// all aminoacids have been scaled to the size of arginine
void draw_alanine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::alanine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_arginine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::arginine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_asparagine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::asparagine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_aspartic_acid(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::aspartic_acid);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_cysteine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::cysteine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_glutamic_acid(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::glutamic_acid);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_glutamine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::glutamine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_glycine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::glycine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_histidine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::histidine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_isoleucine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::isoleucine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_leucine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::leucine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_lysine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::lysine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_methionine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::methionine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_phenylalanine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::phenylalanine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_proline(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::proline);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_serine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::serine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_threonine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::threonine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_tryptophan(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::tryptophan);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_tyrosine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::tyrosine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_valine(
  const player& p,
  sf::RenderWindow& w,
  Sprites_sfml& sprites
)
{
  sf::Sprite& sprite = sprites.get(amino_acid::valine);
  sprite.setPosition(p.get_x(), p.get_y());
  sprite.setRotation(p.get_rotation() + 30);
  w.draw(sprite);
}

void draw_hit_ranges(
  sf::CircleShape hit_range,
  sf::RenderWindow &w
)
{
  const int window_size = w.getSize().x;

  //Must we draw the 'shadow' hitranges left or right?
  const bool must_right{hit_range.getPosition().x < window_size / 2};
  const int dx = must_right ? window_size : -window_size;
  const bool must_down{hit_range.getPosition().y < window_size / 2};
  const int dy = must_down ? window_size : -window_size;
  //Real position
  w.draw(hit_range);
  //Horizontal of player
  hit_range.setPosition(hit_range.getPosition() + sf::Vector2f(dx, 0));
  w.draw(hit_range);
  //Down-Right of player
  hit_range.setPosition(hit_range.getPosition() + sf::Vector2f(0, dy));
  w.draw(hit_range);
  //Bacl Below player
  hit_range.setPosition(hit_range.getPosition() + sf::Vector2f(-dx, 0));
  w.draw(hit_range);
}

void draw_life_bar(
  sf::RectangleShape life_bar,
  sf::RenderWindow &w)
{
  w.draw(life_bar);
}

void respond_to_joystick( //!OCLINT cannot simplify this even more
  player &p3,
  player &p4,
  std::vector<bullet> &bullets)
{
  // player 3 controls
  if(p3.get_hp() > 0)
  {
    if(sf::Joystick::isButtonPressed(0, 0)) { p3.decelerate(); } // A button
    if(sf::Joystick::isButtonPressed(0, 1)) { p3.turn_right(); } // B button
    if(sf::Joystick::isButtonPressed(0, 2)) { p3.turn_left(); } // x button
    if(sf::Joystick::isButtonPressed(0, 3)) { p3.accelerate(); } // Y button
    if(sf::Joystick::isButtonPressed(0, 4)) { // LB button
      bullets.push_back(shoot(p3));
    }
  }

  //player 4 controls
  if(p4.get_hp() > 0)
  {
    if(sf::Joystick::isButtonPressed(1, 0)) { p4.decelerate(); } // A button
    if(sf::Joystick::isButtonPressed(1, 1)) { p4.turn_right(); } // B button
    if(sf::Joystick::isButtonPressed(1, 2)) { p4.turn_left(); } // x button
    if(sf::Joystick::isButtonPressed(1, 3)) { p4.accelerate() ; } // Y button
    if(sf::Joystick::isButtonPressed(1, 4)) { // LB button
      bullets.push_back(shoot(p4));
    }
  }
}

void respond_to_key( //!OCLINT cannot simplify this even more
  player &p1,
  player &p2,
  std::vector<bullet> &bullets
)
{
  // player1 controls
  if(p1.get_hp() > 0)
  {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left )) { p1.turn_left (); }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { p1.turn_right(); }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up   )) { p1.accelerate(); }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down )) { p1.decelerate(); }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      bullets.push_back(shoot(p1));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
      power p = get_power(p1.get_amino_acid());
      do_power(p, bullets);
    }
  }
  // player2 controls
  if(p2.get_hp() > 0)
  {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W  )) { p2.accelerate(); }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D  )) { p2.turn_right(); }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S  )) { p2.decelerate(); }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A  )) { p2.turn_left (); }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
    {
      bullets.push_back(shoot(p2));
    }
  }
}
