#include "helper.h"
#include "player.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(player_construction)
{
  create_sprites();
  sf::Sprite *sprite = new sf::Sprite;
  sf::Texture *texture = new sf::Texture;
  sf::Vector2f position{sf::Vector2f(10.0, 10.0)};

  texture->loadFromFile("Alanine.png");
  sprite->setTexture(*texture);
  sprite->setPosition(position);

  player p(sprite, texture);

  BOOST_CHECK(p.get_position() == position);
  BOOST_CHECK(p.get_sprite() == sprite);
}




