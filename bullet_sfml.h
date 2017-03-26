#ifndef BULLET_SFML_H
#define BULLET_SFML_H

/// Functions and/or classes to display the 'bullet' class
/// using SFML

#include <SFML/Graphics/Sprite.hpp>
#include "bullet.h"

//May be slow
sf::Sprite to_sprite(const bullet& b);

#endif // BULLET_SFML_H
