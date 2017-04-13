#include "player_sfml.h"
#include <cassert>

void draw_player(
  const player& p,
  sf::RenderWindow& w)
{

  switch(p.get_amino_acid()) {
    case amino_acid::alanine:       return draw_alanine      (p, w);
    case amino_acid::arginine:      return draw_arginine     (p, w);
    case amino_acid::asparagine:    return draw_asparagine   (p, w);
    case amino_acid::aspartic_acid: return draw_aspartic_acid(p, w);
    case amino_acid::cysteine:      return draw_cysteine     (p, w);
    case amino_acid::glutamic_acid: return draw_glutamic_acid(p, w);
    case amino_acid::glutamine:     return draw_glutamine    (p, w);
    case amino_acid::glycine:       return draw_glycine      (p, w);
    case amino_acid::histidine:     return draw_histidine    (p, w);
    case amino_acid::isoleucine:    return draw_isoleucine   (p, w);
    case amino_acid::leucine:       return draw_leucine      (p, w);
    case amino_acid::lysine:        return draw_lysine       (p, w);
    case amino_acid::methionine:    return draw_methionine   (p, w);
    case amino_acid::phenylalanine: return draw_phenylalanine(p, w);
    case amino_acid::proline:       return draw_proline      (p, w);
    case amino_acid::serine:        return draw_serine       (p, w);
    case amino_acid::threonine:     return draw_threonine    (p, w);
    case amino_acid::tryptophan:    return draw_tryptophan   (p, w);
    case amino_acid::tyrosine:      return draw_tyrosine     (p, w);
    case amino_acid::valine:        return draw_valine       (p, w);
    default: assert(!"TODO");
  }
  assert(!"should not get here"); //!OCLINT accepted idiom
}

/*void draw_players(
  const std::vector<player>& ps,
  sf::RenderWindow& w)
{
  for (const auto& p: ps) draw_player(p, w);
}*/

void draw_players(
  std::vector<player>& ps,
  sf::RenderWindow &window)
{
  for (auto& p: ps)
  {
    const int window_size = window.getSize().x;
    //sf::Sprite s = *p.get_sprite();
    //Must we draw the 'shadow' player left or right?
    const bool must_right{p.get_x() < window_size / 2};
    const int dx = must_right ? window_size : -window_size;
    const bool must_down{p.get_y() < window_size / 2};
    const int dy = must_down ? window_size : -window_size;
    //Real position
    draw_player(p, window);
    //Horizontal of player
    p.set_position(p.get_x() + dx, p.get_y());
    draw_player(p, window);
    //Down-Right of player
    p.set_position(p.get_x(), p.get_y() +  dy);
    draw_player(p, window);
    //Bacl Below player
    p.set_position(p.get_x() - dx, p.get_y());
    draw_player(p, window);
  }
}

/// all aminoacids have been scaled to the size of arginine
void draw_alanine(
  const player& p,
  sf::RenderWindow& w)
{
  assert(p.get_amino_acid() == amino_acid::alanine);
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Alanine.png");
  auto width = m_texture->getSize().x;
  auto height = m_texture->getSize().y;

  //total size picture in pixels = 781;640 (check in picture)
  //origin of molecule in pixels = 326;362 (check in picture)
  //origin is set 326/781;362/640
  const double x_ratio_origin = 326.0/781.0;
  const double y_ratio_origin = 362.0/640.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/103.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(width * x_ratio_origin, height * y_ratio_origin));
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_arginine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_asparagine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_aspartic_acid(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_cysteine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_glutamic_acid(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_glutamine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_glycine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_histidine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_isoleucine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_leucine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_lysine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_methionine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_phenylalanine(
  const player& p,
  sf::RenderWindow& w)
{
  sf::Sprite * m_sprite = new sf::Sprite;
  sf::Texture * m_texture = new sf::Texture;

  m_texture->loadFromFile("Phenylalanine.png");
  auto x = m_texture->getSize().x;
  auto y = m_texture->getSize().y;
void draw_hit_ranges(
  sf::CircleShape hit_range,
  sf::RenderWindow &window
);
  //total size picture in pixels = 587;832 (check in picture)
  //origin of molecule in pixels = 243;623 (check in picture)
  //origin is set 243;587;623/832
  const double x_ratio_origin = 243.0/587.0;
  const double y_ratio_origin = 623.0/832.0;
  m_sprite->setTexture(*m_texture);
  double scale = 0.12*(70.0/78.0);
  m_sprite->setScale(sf::Vector2f(scale, scale));
  m_sprite->setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_proline(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_serine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_threonine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_tryptophan(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_tyrosine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_valine(
  const player& p,
  sf::RenderWindow& w)
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
  m_sprite->setPosition(p.get_x(), p.get_y());
  m_sprite->setRotation(p.get_rotation() + 30);
  w.draw(*m_sprite);
}

void draw_hit_ranges(
  sf::CircleShape hit_range,
  sf::RenderWindow &window)
{
  const int window_size = window.getSize().x;

  //Must we draw the 'shadow' hitranges left or right?
  const bool must_right{hit_range.getPosition().x < window_size / 2};
  const int dx = must_right ? window_size : -window_size;
  const bool must_down{hit_range.getPosition().y < window_size / 2};
  const int dy = must_down ? window_size : -window_size;
  //Real position
  window.draw(hit_range);
  //Horizontal of player
  hit_range.setPosition(hit_range.getPosition() + sf::Vector2f(dx, 0));
  window.draw(hit_range);
  //Down-Right of player
  hit_range.setPosition(hit_range.getPosition() + sf::Vector2f(0, dy));
  window.draw(hit_range);
  //Bacl Below player
  hit_range.setPosition(hit_range.getPosition() + sf::Vector2f(-dx, 0));
  window.draw(hit_range);
}

void draw_life_bar(
  sf::RectangleShape life_bar,
  sf::RenderWindow &window)
{
  window.draw(life_bar);
}

void respond_to_joystick( //!OCLINT cannot simplify this even more
  player &player3,
  player &player4,
  std::vector<bullet> &bullets)
{
  // player 3 controls
  if(sf::Joystick::isButtonPressed(0, 0)) { player3.decelerate(); } // A button
  if(sf::Joystick::isButtonPressed(0, 1)) { player3.turn_right()  ; } // B button
  if(sf::Joystick::isButtonPressed(0, 2)) { player3.turn_left()   ; } // x button
  if(sf::Joystick::isButtonPressed(0, 3)) { player3.accelerate() ; } // Y button
  if(sf::Joystick::isButtonPressed(0, 4)) { // LB button
    bullets.push_back(shoot(player3));
  }

  //player 4 controls
  if(sf::Joystick::isButtonPressed(1, 0)) { player4.decelerate(); } // A button
  if(sf::Joystick::isButtonPressed(1, 1)) { player4.turn_right()  ; } // B button
  if(sf::Joystick::isButtonPressed(1, 2)) { player4.turn_left()   ; } // x button
  if(sf::Joystick::isButtonPressed(1, 3)) { player4.accelerate() ; } // Y button
  if(sf::Joystick::isButtonPressed(1, 4)) { // LB button
    bullets.push_back(shoot(player4));
  }
}

void respond_to_key( //!OCLINT cannot simplify this even more
  player &player1,
  player &player2,
  std::vector<bullet> &bullets)
{
  // player1 controls
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left )) { player1.turn_left()   ; }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { player1.turn_right()  ; }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up   )) { player1.accelerate() ; }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down )) { player1.decelerate(); }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    bullets.push_back(shoot(player1));
  }
  // player2 controls
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W  )) { player2.accelerate() ; }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D  )) { player2.turn_right()  ; }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S  )) { player2.decelerate(); }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A  )) { player2.turn_left()   ; }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
    bullets.push_back(shoot(player2));
  }
}

