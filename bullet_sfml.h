#ifndef BULLET_SFML_H
#define BULLET_SFML_H

/// Functions and/or classes to display the 'bullet' class
/// using SFML

#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include "bullet.h"

//May be slow, use Sprite_sfml::get_bullet instead
//[[deprecated]]
sf::Sprite& to_sprite(const bullet& b);

#endif // BULLET_SFML_H
