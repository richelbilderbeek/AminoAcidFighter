#include "bullet_sfml.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(bullet_to_sprite_works)
{
  const double damage{10.0};
  const double x{1.2};
  const double y{3.4};
  const double speed_x{0.8};
  const double speed_y{0.6};
  const int world_size{100};
  const bullet b(damage, x, y, speed_x, speed_y);

  BOOST_CHECK_EQUAL(b.get_damage(), damage);
  BOOST_CHECK_EQUAL(b.get_x(), x);
  BOOST_CHECK_EQUAL(b.get_y(), y);
  BOOST_CHECK_EQUAL(b.get_speed_x(), speed_x);
  BOOST_CHECK_EQUAL(b.get_speed_y(), speed_y);

  const sf::Sprite& s = to_sprite(b);
  BOOST_CHECK(s.getTexture());
  BOOST_CHECK_CLOSE(b.get_x(), s.getPosition().x, 0.00001);
  BOOST_CHECK_CLOSE(b.get_y(), s.getPosition().y, 0.00001);
}

