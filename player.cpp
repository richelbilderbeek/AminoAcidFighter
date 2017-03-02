#include <cmath>
#include <cassert>
#include <iostream>

#include "player.h"

player::player(
    sf::Vector2f position,
    sf::Sprite * sprite,
    sf::Texture * texture
  )
  : m_position{position},
    m_speed_x{0.0},
    m_speed_y{0.0},
    m_sprite{sprite},
    m_texture{texture},
    m_turn_speed{0.0}
{}

void player::accellerate()
{
  const auto angle_degrees = m_sprite->getRotation() - 30.0;
  const auto angle_radians = angle_degrees * M_PI / 180.0;
  m_speed_x += std::cos( angle_radians) * 0.1;
  m_speed_y -= std::sin(-angle_radians) * 0.1;
}

player create_player(
  amino_acid aminoacid,
  sf::Vector2f m_position)
{
  switch(aminoacid)
  {
    case amino_acid::alanine:       return create_alanine      (m_position);
    case amino_acid::arginine:      return create_arginine     (m_position);
    case amino_acid::asparagine:    return create_asparagine   (m_position);
    case amino_acid::aspartic_acid: return create_aspartic_acid(m_position);
    case amino_acid::cysteine:      return create_cysteine     (m_position);
    case amino_acid::glutamic_acid: return create_glutamic_acid(m_position);
    case amino_acid::glutamine:     return create_glutamine    (m_position);
    case amino_acid::glycine:       return create_glycine      (m_position);
    case amino_acid::histidine:     return create_histidine    (m_position);
    case amino_acid::isoleucine:    return create_isoleucine   (m_position);
    case amino_acid::leucine:       return create_leucine      (m_position);
    case amino_acid::lysine:        return create_lysine       (m_position);
    case amino_acid::methionine:    return create_methionine   (m_position);
    case amino_acid::phenylalanine: return create_phenylalanine(m_position);
    case amino_acid::proline:       return create_proline      (m_position);
    case amino_acid::serine:        return create_serine       (m_position);
    case amino_acid::threonine:     return create_threonine    (m_position);
    case amino_acid::tryptophan:    return create_tryptophan   (m_position);
    case amino_acid::tyrosine:      return create_tyrosine     (m_position);
    case amino_acid::valine:        return create_valine       (m_position);
  }
  assert(!"should not get here");
}

player create_alanine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Alanine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 781;640 (check in picture)
  //origin of molecule in pixels = 326;362 (check in picture)
  //origin is set 326/781;362/640
  const double x_ratio_origin = 326.0/781.0;
  const double y_ratio_origin = 362.0/640.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/103.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_arginine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Arginine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 543;921 (check in picture)
  //origin of molecule in pixels = 231;730 (check in picture)
  //origin is set 231/543;730/921
  const double x_ratio_origin = 231.0/543.0;
  const double y_ratio_origin = 730.0/921.0;
  m_sprite->setTexture(*m_texture);
  m_sprite->setScale(sf::Vector2f(0.12, 0.12));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_asparagine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Asparagine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 675;740 (check in picture)
  //origin of molecule in pixels = 286;502 (check in picture)
  //origin is set 286/675;502/740
  const double x_ratio_origin = 286.0/675.0;
  const double y_ratio_origin = 502.0/740.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/88.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_aspartic_acid(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("AsparticAcid.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 743;673 (check in picture)
  //origin of molecule in pixels = 314;411 (check in picture)
  //origin is set 314/743;411/673
  const double x_ratio_origin = 314.0/743.0;
  const double y_ratio_origin = 411.0/673.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/97.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_cysteine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Cysteine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 743;673 (check in picture)
  //origin of molecule in pixels = 315;412 (check in picture)
  //origin is set 315/743;412/673
  const double x_ratio_origin = 315.0/743.0;
  const double y_ratio_origin = 412.0/673.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/97.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_glutamic_acid(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("GlutamicAcid.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 674;741 (check in picture)
  //origin of molecule in pixels = 285;504 (check in picture)
  //origin is set 285/741;504/674
  const double x_ratio_origin = 285.0/674.0;
  const double y_ratio_origin = 504.0/741.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/88.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_glutamine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Glutamine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 607;805 (check in picture)
  //origin of molecule in pixels = 249;586 (check in picture)
  //origin is set 249/607;586/805
  const double x_ratio_origin = 249.0/607.0;
  const double y_ratio_origin = 586.0/805.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/81.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_glycine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Glycine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 792;451 (check in picture)
  //origin of molecule in pixels = 336;172 (check in picture)
  //origin is set 336/792;172/451
  const double x_ratio_origin = 336.0/792.0;
  const double y_ratio_origin = 172.0/451.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/103.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_histidine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Histidine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 624;801 (check in picture)
  //origin of molecule in pixels = 266;580 (check in picture)
  //origin is set 266/624;580/801
  const double x_ratio_origin = 266.0/624.0;
  const double y_ratio_origin = 580.0/801.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/81.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_isoleucine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Isoleucine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 669;746 (check in picture)
  //origin of molecule in pixels = 282;512 (check in picture)
  //origin is set 282;669;512/746
  const double x_ratio_origin = 282.0/669.0;
  const double y_ratio_origin = 512.0/746.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/87.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_leucine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Leucine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 660;741 (check in picture)
  //origin of molecule in pixels = 272;504 (check in picture)
  //origin is set 272;660;504/741
  const double x_ratio_origin = 272.0/660.0;
  const double y_ratio_origin = 504.0/741.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/88.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_lysine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Lysine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 578;865 (check in picture)
  //origin of molecule in pixels = 246;663 (check in picture)
  //origin is set 246;578;663/865
  const double x_ratio_origin = 246.0/578.0;
  const double y_ratio_origin = 663.0/865.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/76.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_methionine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Methionine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 597;838 (check in picture)
  //origin of molecule in pixels = 253;628 (check in picture)
  //origin is set 253;597;628/838
  const double x_ratio_origin = 253.0/597.0;
  const double y_ratio_origin = 628.0/838.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/78.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_phenylalanine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Phenylalanine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 587;832 (check in picture)
  //origin of molecule in pixels = 243;623 (check in picture)
  //origin is set 243;587;623/832
  const double x_ratio_origin = 243.0/587.0;
  const double y_ratio_origin = 623.0/832.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/78.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_proline(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Proline.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 805;621 (check in picture)
  //origin of molecule in pixels = 384;364 (check in picture)
  //origin is set 384/805;364/621
  const double x_ratio_origin = 384.0/805.0;
  const double y_ratio_origin = 364.0/621.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/95.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_serine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Serine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 742;673 (check in picture)
  //origin of molecule in pixels = 315;412 (check in picture)
  //origin is set 315/742;412/673
  const double x_ratio_origin = 315.0/742.0;
  const double y_ratio_origin = 412.0/673.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/97.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_threonine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Threonine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 745;670 (check in picture)
  //origin of molecule in pixels = 315;408 (check in picture)
  //origin is set 315/745;408/670
  const double x_ratio_origin = 315.0/745.0;
  const double y_ratio_origin = 408.0/670.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/97.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_tryptophan(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Tryptophan.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 673;742 (check in picture)
  //origin of molecule in pixels = 377;560 (check in picture)
  //origin is set 377/673;560/742
  const double x_ratio_origin = 377.0/673.0;
  const double y_ratio_origin = 560.0/742.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/67.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_tyrosine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Tyrosine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 568;862 (check in picture)
  //origin of molecule in pixels = 235;657 (check in picture)
  //origin is set 235/568;657/862
  const double x_ratio_origin = 235.0/568.0;
  const double y_ratio_origin = 657.0/862.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/76.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

player create_valine(
  sf::Vector2f m_position)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Valine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;

  //total size picture in pixels = 745;670 (check in picture)
  //origin of molecule in pixels = 315;409 (check in picture)
  //origin is set 315/745;409/670
  const double x_ratio_origin = 315.0/745.0;
  const double y_ratio_origin = 409.0/670.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/97.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(m_position);
  return player(m_position, m_sprite, m_texture);
}

void player::deccellerate()
{
  const auto angle_degrees = m_sprite->getRotation() - 30.0;
  const auto angle_radians = angle_degrees * M_PI / 180.0;
  m_speed_x -= std::cos( angle_radians) * 0.1;
  m_speed_y += std::sin(-angle_radians) * 0.1;
}

void draw(
  const player p,
  sf::RenderWindow &window)
{
  const int window_size = window.getSize().x;
  sf::Sprite s = *p.get_sprite();
  //Must we draw the 'shadow' player left or right?
  const bool must_right{s.getPosition().x < window_size / 2};
  const int dx = must_right ? window_size : -window_size;
  const bool must_down{s.getPosition().y < window_size / 2};
  const int dy = must_down ? window_size : -window_size;
  //Real position
  window.draw(s);
  //Horizontal of player
  s.setPosition(s.getPosition() + sf::Vector2f(dx, 0));
  window.draw(s);
  //Down-Right of player
  s.setPosition(s.getPosition() + sf::Vector2f(0, dy));
  window.draw(s);
  //Bacl Below player
  s.setPosition(s.getPosition() + sf::Vector2f(-dx, 0));
  window.draw(s);
}

void player::move(const int m_window_size)
{
  assert(m_sprite);
  assert(m_window_size >= 1.0);
  //Move
  {
    const auto x = m_sprite->getPosition().x;
    const auto y = m_sprite->getPosition().y;
    const auto new_x = std::fmod(x + m_speed_x + m_window_size, m_window_size);
    const auto new_y = std::fmod(y + m_speed_y + m_window_size, m_window_size);
    set_position(new_x, new_y);
  }
  //Rotate
  {
    m_sprite->setRotation(m_sprite->getRotation() + m_turn_speed);
  }
}

void respond_to_joystick( //!OCLINT cannot simplify this even more
  player &player3,
  player &player4,
  std::vector<bullet> &bullets,
  int window_size)
{
  // player 3 controls
  if(sf::Joystick::isButtonPressed(0, 0)) { player3.deccellerate(); } // A button
  if(sf::Joystick::isButtonPressed(0, 1)) { player3.turn_right()  ; } // B button
  if(sf::Joystick::isButtonPressed(0, 2)) { player3.turn_left()   ; } // x button
  if(sf::Joystick::isButtonPressed(0, 3)) { player3.accellerate() ; } // Y button
  if(sf::Joystick::isButtonPressed(0, 4)) // LB button
  {
    bullets.push_back(shoot(player3, window_size));
  }

  //player 4 controls
  if(sf::Joystick::isButtonPressed(1, 0)) { player4.deccellerate(); } // A button
  if(sf::Joystick::isButtonPressed(1, 1)) { player4.turn_right()  ; } // B button
  if(sf::Joystick::isButtonPressed(1, 2)) { player4.turn_left()   ; } // x button
  if(sf::Joystick::isButtonPressed(1, 3)) { player4.accellerate() ; } // Y button
  if(sf::Joystick::isButtonPressed(1, 4)) // LB button
  {
    bullets.push_back(shoot(player4, window_size));
  }
}

void respond_to_key( //!OCLINT cannot simplify this even more
  player &player1,
  player &player2,
  std::vector<bullet> &bullets,
  int window_size)
{
  // player1 controls
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left )) { player1.turn_left()   ; }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { player1.turn_right()  ; }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up   )) { player1.accellerate() ; }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down )) { player1.deccellerate(); }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    bullets.push_back(shoot(player1, window_size));
  }
  // player2 controls
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W  )) { player2.accellerate() ; }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D  )) { player2.turn_right()  ; }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S  )) { player2.deccellerate(); }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A  )) { player2.turn_left()   ; }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
  {
    bullets.push_back(shoot(player2, window_size));
  }
}

bullet shoot(
  const player& player1,
  const int window_size)
{
  auto glycine_rot_degree = player1.get_rotation() + 10.7389;
  //10.7389 = angle from turn origin to shooter origin
  auto glycine_rot_radians = glycine_rot_degree * M_PI / 180;
  auto glycine_pos_x = player1.get_position().x;
  auto glycine_pos_y = player1.get_position().y;

  float x_shooter = glycine_pos_x + (std::cos(glycine_rot_radians) * 42.034985);
  float y_shooter = glycine_pos_y - (-std::sin(glycine_rot_radians) * 42.034985);
  //42.034985 = length from turn origin to shooter origin
  //std::cout << x_shooter << ", " << y_shooter << std::endl;
  sf::Vector2f position = { x_shooter, y_shooter};
  double angle_deg = glycine_rot_degree + 110.0;
  double angle_rad = angle_deg * M_PI / 180;
  const double speed_x{ std::sin(angle_rad) * 1.5};
  const double speed_y{-std::cos(angle_rad) * 1.5};
  return bullet(10, position, speed_x, speed_y, window_size);
}

void player::stop()
{
  m_speed_x = 0.0;
  m_speed_y = 0.0;
  m_turn_speed = 0.0;
}

void player::turn_left()
{
  m_turn_speed -= 0.1;
}

void player::turn_right()
{
  m_turn_speed += 0.1;
}
