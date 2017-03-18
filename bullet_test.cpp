#include "bullet.h"
#include "helper.h"

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(bullet_construction)
{
  create_sprites();
  const bullet b(10.0, sf::Vector2f(10.0, 10.0), 0.8, 0.6, 100);
}








BOOST_AUTO_TEST_CASE(remove_out_of_screen_bullets_removes_bullets)
{

}


