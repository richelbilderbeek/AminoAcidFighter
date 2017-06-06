#include "sprites_sfml.h"

#include <cassert>
#include "helper.h"

Sprites_sfml::Sprites_sfml() //!OCLINT Let @CarmenIJsebaart clean this up :-)
{
  //Create all resources needed: pictures, sounds, etcetera
  create_resources();

  //Filename, x_ratio_origin, y_ratio_origin, scale
  const std::vector<std::tuple<amino_acid, double, double, double>> v =
  {
    std::make_tuple(amino_acid::alanine      , 326.0/781.0, 362.0/640.0, 0.12*(70.0/103.0)),
    std::make_tuple(amino_acid::arginine     , 231.0/543.0, 730.0/921.0, 0.12             ),
    std::make_tuple(amino_acid::asparagine   , 286.0/675.0, 502.0/740.0, 0.12*(70.0/88.0 )),
    std::make_tuple(amino_acid::aspartic_acid, 314.0/743.0, 411.0/673.0, 0.12*(70.0/97.0 )),
    std::make_tuple(amino_acid::cysteine     , 315.0/743.0, 412.0/673.0, 0.12*(70.0/97.0 )),
    std::make_tuple(amino_acid::glutamic_acid, 285.0/674.0, 504.0/741.0, 0.12*(70.0/88.0 )),
    std::make_tuple(amino_acid::glutamine    , 249.0/607.0, 586.0/805.0, 0.12*(70.0/81.0 )),
    std::make_tuple(amino_acid::glycine      , 336.0/792.0, 172.0/451.0, 0.12*(70.0/103.0)),
    std::make_tuple(amino_acid::histidine    , 266.0/624.0, 580.0/801.0, 0.12*(70.0/81.0 )),
    std::make_tuple(amino_acid::isoleucine   , 282.0/669.0, 512.0/746.0, 0.12*(70.0/87.0 )),
    std::make_tuple(amino_acid::leucine      , 272.0/660.0, 504.0/741.0, 0.12*(70.0/88.0 )),
    std::make_tuple(amino_acid::lysine       , 246.0/578.0, 663.0/865.0, 0.12*(70.0/76.0 )),
    std::make_tuple(amino_acid::methionine   , 253.0/597.0, 628.0/838.0, 0.12*(70.0/78.0 )),
    std::make_tuple(amino_acid::phenylalanine, 243.0/587.0, 623.0/832.0, 0.12*(70.0/78.0 )),
    std::make_tuple(amino_acid::proline      , 384.0/805.0, 364.0/621.0, 0.12*(70.0/95.0 )),
    std::make_tuple(amino_acid::serine       , 315.0/742.0, 412.0/673.0, 0.12*(70.0/97.0 )),
    std::make_tuple(amino_acid::threonine    , 315.0/745.0, 408.0/670.0, 0.12*(70.0/97.0 )),
    std::make_tuple(amino_acid::tryptophan   , 377.0/673.0, 560.0/742.0, 0.12*(70.0/67.0 )),
    std::make_tuple(amino_acid::tyrosine     , 235.0/568.0, 657.0/862.0, 0.12*(70.0/76.0 )),
    std::make_tuple(amino_acid::valine       , 315.0/745.0, 409.0/670.0, 0.12*(70.0/97.0 ))
  };

  for(const auto& t: v)
  {
    const amino_acid aa  = std::get<0>(t);
    const double x_ratio = std::get<1>(t);
    const double y_ratio = std::get<2>(t);
    const double scale   = std::get<3>(t);

    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;

    texture->loadFromFile(to_str(aa) + ".png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    sprite.setTexture(*texture);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio, y * y_ratio));
    m_aas.insert(std::make_pair(aa, sprite));
    m_textures.push_back(texture);
  }

  //Load the bullet
  {
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Bullet.png");
    m_bullet.setTexture(*texture);
    double scale = 0.12*(70.0/96.0);
    m_bullet.setScale(sf::Vector2f(scale, scale));
    /// bullet is scaled to the size of arginine
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    double ratio = 0.5;
    m_bullet.setOrigin(sf::Vector2f(x * ratio, y * ratio));
    m_textures.push_back(texture);
  }
}

sf::Sprite& Sprites_sfml::get(const amino_acid aa) noexcept
{
  const auto here = m_aas.find(aa);
  assert(here != m_aas.end());
  return (*here).second;
}
