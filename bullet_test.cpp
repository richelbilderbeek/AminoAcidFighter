#include "bullet.h"
#include "helper.h"

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(bullet_construction)
{
  create_sprites();
  const double damage{10.0};
  const sf::Vector2f position{sf::Vector2f(10.0, 10.0)};
  const double speed_x{0.8};
  const double speed_y{0.6};
  const int window_size{100};

  const bullet b(damage, position, speed_x, speed_y, window_size);

  BOOST_CHECK_EQUAL(b.get_damage(), damage);
  BOOST_CHECK      (b.get_position() == position);
  BOOST_CHECK_EQUAL(b.get_speed_x(), speed_x);
  BOOST_CHECK_EQUAL(b.get_speed_y(), speed_y);
}

BOOST_AUTO_TEST_CASE(remove_out_of_screen_bullets_removes_bullets)
{

}


