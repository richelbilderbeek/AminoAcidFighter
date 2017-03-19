#include "bullet.h"
#include "helper.h"

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(bullet_construction)
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
}

BOOST_AUTO_TEST_CASE(bullet_set_and_get_must_be_symmetrical)
{
  const double damage{10.0};
  const double x{1.2};
  const double y{3.4};
  const double speed_x{0.8};
  const double speed_y{0.6};
  const int world_size{100};
  bullet b(damage, x, y, speed_x, speed_y);

  const double new_x{12.34};
  const double new_y{56.78};
  b.set_position(new_x, new_y);
  BOOST_CHECK_EQUAL(b.get_x(), new_x);
  BOOST_CHECK_EQUAL(b.get_y(), new_y);

}

BOOST_AUTO_TEST_CASE(remove_out_of_screen_bullets_test)
{
  using position = std::pair<double, double>;
  const double damage{10.0};
  const position pos1{-10.0,  10.0}; //Left
  const position pos2{ 10.0, -10.0}; //Top
  const position pos3{110.0,  10.0}; //Right
  const position pos4{ 10.0, 110.0}; //Bottom
  const double speed_x{0.8};
  const double speed_y{0.6};
  const int world_size{100};

  const bullet a(damage, pos1.first, pos1.second, speed_x, speed_y);
  const bullet b(damage, pos2.first, pos2.second, speed_x, speed_y);
  const bullet c(damage, pos3.first, pos3.second, speed_x, speed_y);
  const bullet d(damage, pos4.first, pos4.second, speed_x, speed_y);
  std::vector<bullet> bullets = { a, b, c, d };

  BOOST_CHECK_EQUAL(bullets.size(), 4);
  remove_out_of_screen_bullets(bullets, world_size);
  BOOST_CHECK_EQUAL(bullets.size(), 0);
}

BOOST_AUTO_TEST_CASE(keep_in_screen_bullets)
{
  using position = std::pair<double, double>;
  const double damage{10.0};
  const position pos{10.0, 10.0};
  const double speed_x{0.8};
  const double speed_y{0.6};
  const int world_size{100};

  const bullet b(damage, pos.first, pos.second, speed_x, speed_y);
  std::vector<bullet> bullets = { b };

  BOOST_CHECK_EQUAL(bullets.size(), 1);
  remove_out_of_screen_bullets(bullets, world_size);
  BOOST_CHECK_EQUAL(bullets.size(), 1);
}

BOOST_AUTO_TEST_CASE(check_move)
{
  using position = std::pair<double, double>;
  const double damage{10.0};
  const position pos{10.0, 10.0};
  const double speed_x{0.8};
  const double speed_y{0.6};
  const int world_size{100};

  bullet b(damage, pos.first, pos.second, speed_x, speed_y);
  const position pos_before = { b.get_x(), b.get_y() };
  b.move();
  const position pos_after = { b.get_x(), b.get_y() };
  BOOST_CHECK_NE(pos_before.first, pos_after.first);
  BOOST_CHECK_NE(pos_before.second, pos_after.second);
  BOOST_CHECK_CLOSE(pos_after.first, pos_before.first + speed_x, 0.0001);
  BOOST_CHECK_CLOSE(pos_after.second, pos_before.second + speed_y, 0.0001);
}
