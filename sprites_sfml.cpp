#include "sprites_sfml.h"

#include <cassert>

#include "helper.h"

Sprites_sfml::Sprites_sfml() //!OCLINT Let @CarmenIJsebaart clean this up :-)
{
  //Create all resources needed: pictures, sounds, etcetera
  create_resources();

  //Load the resources
  //Alanine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Alanine.png");
    auto width = texture->getSize().x;
    auto height = texture->getSize().y;
    //origin is set 326/781;362/640
    const double x_ratio_origin = 326.0/781.0;
    const double y_ratio_origin = 362.0/640.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/103.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(width * x_ratio_origin, height * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::alanine, sprite));
    m_textures.push_back(texture);
  }
  //Arginine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Arginine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 231/543;730/921
    const double x_ratio_origin = 231.0/543.0;
    const double y_ratio_origin = 730.0/921.0;
    sprite.setTexture(*texture);
    sprite.setScale(sf::Vector2f(0.12, 0.12));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::arginine, sprite));
    m_textures.push_back(texture);
  }
  //Asparagine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Asparagine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 286/675;502/740
    const double x_ratio_origin = 286.0/675.0;
    const double y_ratio_origin = 502.0/740.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/88.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::asparagine, sprite));
    m_textures.push_back(texture);
  }
  //Aspartic acid
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("AsparticAcid.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 314/743;411/673
    const double x_ratio_origin = 314.0/743.0;
    const double y_ratio_origin = 411.0/673.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/97.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::aspartic_acid, sprite));
    m_textures.push_back(texture);
  }
  //Cysteine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Cysteine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 315/743;412/673
    const double x_ratio_origin = 315.0/743.0;
    const double y_ratio_origin = 412.0/673.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/97.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::cysteine, sprite));
    m_textures.push_back(texture);
  }
  //Glutamic acid
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("GlutamicAcid.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 285/741;504/674
    const double x_ratio_origin = 285.0/674.0;
    const double y_ratio_origin = 504.0/741.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/88.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::glutamic_acid, sprite));
    m_textures.push_back(texture);
  }
  //Glutamine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Glutamine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 249/607;586/805
    const double x_ratio_origin = 249.0/607.0;
    const double y_ratio_origin = 586.0/805.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/81.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::glutamine, sprite));
    m_textures.push_back(texture);
  }
  //Glycine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Glycine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 336/792;172/451
    const double x_ratio_origin = 336.0/792.0;
    const double y_ratio_origin = 172.0/451.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/103.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::glycine, sprite));
    m_textures.push_back(texture);
  }
  //Histidine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Histidine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 266/624;580/801
    const double x_ratio_origin = 266.0/624.0;
    const double y_ratio_origin = 580.0/801.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/81.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::histidine, sprite));
    m_textures.push_back(texture);
  }
  //Isoleucine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Isoleucine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 282;669;512/746
    const double x_ratio_origin = 282.0/669.0;
    const double y_ratio_origin = 512.0/746.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/87.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::isoleucine, sprite));
    m_textures.push_back(texture);
  }
  //Leucine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Leucine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 272;660;504/741
    const double x_ratio_origin = 272.0/660.0;
    const double y_ratio_origin = 504.0/741.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/88.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::leucine, sprite));
    m_textures.push_back(texture);
  }
  //Lysine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Lysine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 246;578;663/865
    const double x_ratio_origin = 246.0/578.0;
    const double y_ratio_origin = 663.0/865.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/76.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::lysine, sprite));
    m_textures.push_back(texture);
  }
  //Methionine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Methionine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 253;597;628/838
    const double x_ratio_origin = 253.0/597.0;
    const double y_ratio_origin = 628.0/838.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/78.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::methionine, sprite));
    m_textures.push_back(texture);
  }
  //Phenylalanine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Phenylalanine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 243;587;623/832
    const double x_ratio_origin = 243.0/587.0;
    const double y_ratio_origin = 623.0/832.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/78.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::phenylalanine, sprite));
    m_textures.push_back(texture);
  }
  //Proline
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Proline.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 384/805;364/621
    const double x_ratio_origin = 384.0/805.0;
    const double y_ratio_origin = 364.0/621.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/95.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::proline, sprite));
    m_textures.push_back(texture);
  }
  //Serine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Serine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 315/742;412/673
    const double x_ratio_origin = 315.0/742.0;
    const double y_ratio_origin = 412.0/673.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/97.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::serine, sprite));
    m_textures.push_back(texture);
  }
  //Threonine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Threonine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 315/745;408/670
    const double x_ratio_origin = 315.0/745.0;
    const double y_ratio_origin = 408.0/670.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/97.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::threonine, sprite));
    m_textures.push_back(texture);
  }
  //Tryptophan
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Tryptophan.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 377/673;560/742
    const double x_ratio_origin = 377.0/673.0;
    const double y_ratio_origin = 560.0/742.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/67.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::tryptophan, sprite));
    m_textures.push_back(texture);
  }
  //Tyrosine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Tyrosine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 235/568;657/862
    const double x_ratio_origin = 235.0/568.0;
    const double y_ratio_origin = 657.0/862.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/76.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::tyrosine, sprite));
    m_textures.push_back(texture);
  }
  //Valine
  {
    sf::Sprite sprite;
    sf::Texture * const texture = new sf::Texture;
    texture->loadFromFile("Valine.png");
    auto x = texture->getSize().x;
    auto y = texture->getSize().y;
    //origin is set 315/745;409/670
    const double x_ratio_origin = 315.0/745.0;
    const double y_ratio_origin = 409.0/670.0;
    sprite.setTexture(*texture);
    double scale = 0.12*(70.0/97.0);
    sprite.setScale(sf::Vector2f(scale, scale));
    sprite.setOrigin(sf::Vector2f(x * x_ratio_origin, y * y_ratio_origin));
    m_aas.insert(std::make_pair(amino_acid::valine, sprite));
    m_textures.push_back(texture);
  }
}

sf::Sprite& Sprites_sfml::get(const amino_acid aa) noexcept
{
  const auto here = m_aas.find(aa);
  assert(here != m_aas.end());
  return (*here).second;
}
