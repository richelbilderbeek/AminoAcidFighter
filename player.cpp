#include <iostream>
#include "player.h"
#include <cmath>


player::player(const int any_window_size, sf::Vector2f position, amino_acid aminoacid)
  : m_position{position},
    m_speed_x{0.0},
    m_speed_y{0.0},
    m_sprite{},
    m_texture{},
    m_turn_speed{0.0},
    m_window_size{any_window_size}
{
  switch(aminoacid)
  {
    case amino_acid::alanine:
    {
        m_texture.loadFromFile("Alanine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 744;672 (check in picture)
        //origin of molecule in pixels = 315;409 (check in picture)
        //origin is set 315/744;409/672
        const double x_ratio_origin = 315.0/744.0;
        const double y_ratio_origin = 409.0/672.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
    }
    case amino_acid::arginine:
    {
        m_texture.loadFromFile("Arginine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 543;921 (check in picture)
        //origin of molecule in pixels = 231;730 (check in picture)
        //origin is set 231/543;730/921
        const double x_ratio_origin = 231.0/543.0;
        const double y_ratio_origin = 730.0/921.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
    }
    case amino_acid::asparagine:
    {
        m_texture.loadFromFile("Asparagine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 675;740 (check in picture)
        //origin of molecule in pixels = 286;502 (check in picture)
        //origin is set 286/675;502/740
        const double x_ratio_origin = 286.0/675.0;
        const double y_ratio_origin = 502.0/740.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
    }
    case amino_acid::aspartic_acid:
    {
        m_texture.loadFromFile("AsparticAcid.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 743;673 (check in picture)
        //origin of molecule in pixels = 314;411 (check in picture)
        //origin is set 314/743;411/673
        const double x_ratio_origin = 314.0/743.0;
        const double y_ratio_origin = 411.0/673.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
    }
    case amino_acid::cysteine:
    {
        m_texture.loadFromFile("Cysteine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 743;673 (check in picture)
        //origin of molecule in pixels = 315;412 (check in picture)
        //origin is set 315/743;412/673
        const double x_ratio_origin = 315.0/743.0;
        const double y_ratio_origin = 412.0/673.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
    }
    case amino_acid::glutamic_acid:
    {
        m_texture.loadFromFile("GlutamicAcid.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 674;741 (check in picture)
        //origin of molecule in pixels = 285;504 (check in picture)
        //origin is set 285/741;504/674
        const double x_ratio_origin = 285.0/674.0;
        const double y_ratio_origin = 504.0/741.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
    }
    case amino_acid::glutamine:
    {
        m_texture.loadFromFile("Glutamine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 548;805 (check in picture)
        //origin of molecule in pixels = 264;585 (check in picture)
        //origin is set 264/548;585/805
        const double x_ratio_origin = 264.0/548.0;
        const double y_ratio_origin = 585.0/805.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
    }
    case amino_acid::glycine:
    {
      m_texture.loadFromFile("Glycine.png");
      auto x = m_texture.getSize().x;
      auto y = m_texture.getSize().y;

      //total size picture in pixels = 792;451 (check in picture)
      //origin of molecule in pixels = 336;172 (check in picture)
      //origin is set 336/792;172/451
      const double x_ratio_origin = 336.0/792.0;
      const double y_ratio_origin = 172.0/451.0;
      m_sprite.setTexture(m_texture);
      m_sprite.setScale(sf::Vector2f(0.1, 0.1));
      m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
      m_sprite.setPosition(m_position);
      break;
    }
    case amino_acid::histidine:
    {
        m_texture.loadFromFile("Histidine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 624;801 (check in picture)
        //origin of molecule in pixels = 266;580 (check in picture)
        //origin is set 266/624;580/801
        const double x_ratio_origin = 266.0/624.0;
        const double y_ratio_origin = 580.0/801.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
    }
    case amino_acid::isoleucine:
    {
        m_texture.loadFromFile("Isoleucine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 669;746 (check in picture)
        //origin of molecule in pixels = 282;512 (check in picture)
        //origin is set 282;669;512/746
        const double x_ratio_origin = 282.0/669.0;
        const double y_ratio_origin = 512.0/746.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
    }
    case amino_acid::leucine:
    {
        m_texture.loadFromFile("Leucine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 660;741 (check in picture)
        //origin of molecule in pixels = 272;504 (check in picture)
        //origin is set 272;660;504/741
        const double x_ratio_origin = 272.0/660.0;
        const double y_ratio_origin = 504.0/741.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
      }
    case amino_acid::lysine:
    {
        m_texture.loadFromFile("Lysine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 578;865 (check in picture)
        //origin of molecule in pixels = 246;663 (check in picture)
        //origin is set 246;578;663/865
        const double x_ratio_origin = 246.0/578.0;
        const double y_ratio_origin = 663.0/865.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
      }
    case amino_acid::methionine:
    {
        m_texture.loadFromFile("Methionine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 597;838 (check in picture)
        //origin of molecule in pixels = 253;628 (check in picture)
        //origin is set 253;597;628/838
        const double x_ratio_origin = 253.0/597.0;
        const double y_ratio_origin = 628.0/838.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
      }
    case amino_acid::phenylalanine:
    {
        m_texture.loadFromFile("Phenylalanine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 587;832 (check in picture)
        //origin of molecule in pixels = 243;623 (check in picture)
        //origin is set 243;587;623/832
        const double x_ratio_origin = 243.0/587.0;
        const double y_ratio_origin = 623.0/832.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
      }
    case amino_acid::proline:
    {
        m_texture.loadFromFile("Proline.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 805;621 (check in picture)
        //origin of molecule in pixels = 384;364 (check in picture)
        //origin is set 384/805;364/621
        const double x_ratio_origin = 384.0/805.0;
        const double y_ratio_origin = 364.0/621.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
      }
    case amino_acid::serine:
    {
        m_texture.loadFromFile("Serine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 742;673 (check in picture)
        //origin of molecule in pixels = 315;412 (check in picture)
        //origin is set 315/742;412/673
        const double x_ratio_origin = 315.0/742.0;
        const double y_ratio_origin = 412.0/673.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
      }
    case amino_acid::threonine:
    {
        m_texture.loadFromFile("Threonine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 745;670 (check in picture)
        //origin of molecule in pixels = 315;408 (check in picture)
        //origin is set 315/745;408/670
        const double x_ratio_origin = 315.0/745.0;
        const double y_ratio_origin = 408.0/670.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
      }
    case amino_acid::tryptophan:
    {
        m_texture.loadFromFile("Tryptophan.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 673;742 (check in picture)
        //origin of molecule in pixels = 377;560 (check in picture)
        //origin is set 377/673;560/742
        const double x_ratio_origin = 377.0/673.0;
        const double y_ratio_origin = 560.0/742.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
      }
    case amino_acid::tyrosine:
    {
        m_texture.loadFromFile("Tyrosine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 568;862 (check in picture)
        //origin of molecule in pixels = 235;657 (check in picture)
        //origin is set 235/568;657/862
        const double x_ratio_origin = 235.0/568.0;
        const double y_ratio_origin = 657.0/862.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
      }
    case amino_acid::valine:
    {
        m_texture.loadFromFile("Valine.png");
        auto x = m_texture.getSize().x;
        auto y = m_texture.getSize().y;

        //total size picture in pixels = 745;670 (check in picture)
        //origin of molecule in pixels = 315;409 (check in picture)
        //origin is set 315/745;409/670
        const double x_ratio_origin = 315.0/745.0;
        const double y_ratio_origin = 409.0/670.0;
        m_sprite.setTexture(m_texture);
        m_sprite.setScale(sf::Vector2f(0.1, 0.1));
        m_sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
        m_sprite.setPosition(m_position);
        break;
      }
    default:
    {
      std::cout << "No aminoacid!!!!";
      break;
    }
  }
}

void player::accellerate()
{
  const auto angle_degrees = m_sprite.getRotation() - 30.0;
  const auto angle_radians = angle_degrees * M_PI / 180.0;
  m_speed_x += std::cos( angle_radians) * 0.01;
  m_speed_y -= std::sin(-angle_radians) * 0.01;
}

void player::deccellerate()
{
  const auto angle_degrees = m_sprite.getRotation() - 30.0;
  const auto angle_radians = angle_degrees * M_PI / 180.0;
  m_speed_x -= std::cos( angle_radians) * 0.01;
  m_speed_y += std::sin(-angle_radians) * 0.01;
}


void draw(const player p, sf::RenderWindow &window)
{
  const int window_size = window.getSize().x;
  sf::Sprite s = p.get_sprite();
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

void player::move()
{
  //Move
  {
    const auto x = m_sprite.getPosition().x;
    const auto y = m_sprite.getPosition().y;
    const auto new_x = std::fmod(x + m_speed_x + m_window_size, m_window_size);
    const auto new_y = std::fmod(y + m_speed_y + m_window_size, m_window_size);
    setPosition(new_x, new_y);
  }
  //Rotate
  {
    m_sprite.setRotation(m_sprite.getRotation() + m_turn_speed);

  }
}

bullet shoot(const player& player1, const int window_size)
{
  auto glycine_rot_degree = player1.getRotation() + 10.7389;
  //10.7389 = angle from turn origin to shooter origin
  auto glycine_rot_radians = glycine_rot_degree * M_PI / 180;
  auto glycine_pos_x = player1.getPosition().x;
  auto glycine_pos_y = player1.getPosition().y;

  float x_shooter = glycine_pos_x + (std::cos(glycine_rot_radians) * 42.034985);
  float y_shooter = glycine_pos_y - (-std::sin(glycine_rot_radians) * 42.034985);
  //42.034985 = length from turn origin to shooter origin
  //std::cout << x_shooter << ", " << y_shooter << std::endl;
  sf::Vector2f position = { x_shooter, y_shooter};
  double angle_deg = glycine_rot_degree + 110.0;
  double angle_rad = angle_deg * M_PI / 180;
  const double speed_x{ std::sin(angle_rad) * 0.05};
  const double speed_y{-std::cos(angle_rad) * 0.05};
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
  m_turn_speed -= 0.01;
  //setRotation(getRotation() - 5.0);
}

void player::turn_right()
{
  m_turn_speed += 0.01;
  //setRotation(getRotation() + 5.0);
}
