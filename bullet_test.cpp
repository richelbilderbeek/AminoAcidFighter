#include "bullet.h"
#include "helper.h"

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(bullet_construction)
{
  create_sprites();
  const double damage{10.0};
  const sf::Vector2f old_position{sf::Vector2f(10.0, 10.0)};
  const double speed_x{0.8};
  const double speed_y{0.6};
  const int window_size{100};

  bullet b(damage, old_position, speed_x, speed_y, window_size);

  BOOST_CHECK_EQUAL(b.get_damage(), damage);
  BOOST_CHECK_EQUAL(b.get_speed_x(), speed_x);
  BOOST_CHECK_EQUAL(b.get_speed_y(), speed_y);
  BOOST_CHECK(b.get_position() == old_position);

  const sf::Vector2f new_position{sf::Vector2f(50.0, 25.0)};
  b.set_position(new_position);

  BOOST_CHECK(b.get_position() == new_position);

}

BOOST_AUTO_TEST_CASE(remove_out_of_screen_bullets_test)
{
  const double damage{10.0};
  const sf::Vector2f position1{sf::Vector2f(-10.0,  10.0)}; //Left
  const sf::Vector2f position2{sf::Vector2f( 10.0, -10.0)}; //Top
  const sf::Vector2f position3{sf::Vector2f(110.0,  10.0)}; //Right
  const sf::Vector2f position4{sf::Vector2f( 10.0, 110.0)}; //Bottom
  const double speed_x{0.8};
  const double speed_y{0.6};
  const int window_size{100};

  const bullet a(damage, position1, speed_x, speed_y, window_size);
  const bullet b(damage, position2, speed_x, speed_y, window_size);
  const bullet c(damage, position3, speed_x, speed_y, window_size);
  const bullet d(damage, position4, speed_x, speed_y, window_size);
  std::vector<bullet> bullets;
  bullets.push_back(a);
  bullets.push_back(b);
  bullets.push_back(c);
  bullets.push_back(d);

  BOOST_CHECK_EQUAL(bullets.size(), 4);
  remove_out_of_screen_bullets(bullets, window_size);
  BOOST_CHECK_EQUAL(bullets.size(), 0);
}

BOOST_AUTO_TEST_CASE(keep_in_screen_bullets)
{
  const double damage{10.0};
  const sf::Vector2f position{sf::Vector2f(10.0, 10.0)};
  const double speed_x{0.8};
  const double speed_y{0.6};
  const int window_size{100};

  const bullet b(damage, position, speed_x, speed_y, window_size);
  std::vector<bullet> bullets;
  bullets.push_back(b);

  BOOST_CHECK_EQUAL(bullets.size(), 1);
  remove_out_of_screen_bullets(bullets, window_size);
  BOOST_CHECK_EQUAL(bullets.size(), 1);
}

BOOST_AUTO_TEST_CASE(check_move)
{
  const double damage{10.0};
  const sf::Vector2f position{sf::Vector2f(10.0, 10.0)};
  const double speed_x{0.8};
  const double speed_y{0.6};
  const int window_size{100};

  bullet b(damage, position, speed_x, speed_y, window_size);
  const auto position_before = b.get_position();
  b.move();
  const auto position_after = b.get_position();
  BOOST_CHECK_NE(position_before.x, position_after.x);
  BOOST_CHECK_NE(position_before.y, position_after.y);
  BOOST_CHECK_CLOSE(position_after.x, position_before.x + speed_x, 0.0001);
  BOOST_CHECK_CLOSE(position_after.y, position_before.y + speed_y, 0.0001);
}
