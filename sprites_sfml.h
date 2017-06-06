#ifndef SPRITES_SFML_H
#define SPRITES_SFML_H

#include <map>
#include <SFML/Graphics.hpp>
#include "amino_acid.h"

class Sprites_sfml
{
public:
  //Prepare all sprites
  Sprites_sfml();

  //sf::Sprite& get_alanine() const noexcept { return m_alanine; }
  sf::Sprite& get(const amino_acid aa) noexcept;
  sf::Sprite& get_bullet() noexcept { return m_bullet; }
  sf::Sprite& get_background() noexcept { return m_background; }


  private:
  std::map<amino_acid, sf::Sprite> m_aas;
  std::vector<sf::Texture*> m_textures;
  sf::Sprite m_bullet;
  sf::Sprite m_background;
};

#endif // SPRITES_SFML_H
