#include <boost/test/unit_test.hpp>
#include "game.h"

BOOST_AUTO_TEST_CASE(check_create_players)
{
  const double world_size{314.159};
  const std::vector<amino_acid> amino_acids =
  {
    amino_acid::isoleucine,
    amino_acid::tryptophan,
    amino_acid::arginine,
    amino_acid::asparagine
  };
  const auto players = create_players(amino_acids, world_size);

  BOOST_CHECK(players.size() == amino_acids.size());
  // Players must be arranged like
  //
  //  [0]  [1]
  //
  //  [2]  [3]
  //
  // in the world
  BOOST_CHECK_EQUAL(players[0].get_x(), players[2].get_x());
  BOOST_CHECK_EQUAL(players[1].get_x(), players[3].get_x());

  BOOST_CHECK_EQUAL(players[0].get_y(), players[1].get_y());
  BOOST_CHECK_EQUAL(players[2].get_y(), players[3].get_y());

  BOOST_CHECK_NE(players[0].get_x(), players[1].get_x());
  BOOST_CHECK_NE(players[0].get_y(), players[2].get_y());
}

BOOST_AUTO_TEST_CASE(check_game_construction)
{
  const double world_size{314.159};
  const std::vector<amino_acid> amino_acids =
  {
    amino_acid::alanine,
    amino_acid::glycine
  };
  const game g(amino_acids, world_size);
  BOOST_CHECK(g.get_players().size() == amino_acids.size());

}

BOOST_AUTO_TEST_CASE(check_create_test_game_1)
{
  const double world_size{314.159};
  const std::vector<amino_acid> amino_acids =
  {
    amino_acid::tyrosine,
    amino_acid::glycine
  };
  const game g(amino_acids, world_size);
  const game h = create_test_game_1();
  BOOST_CHECK(g.get_players() == h.get_players());
  BOOST_CHECK_EQUAL(g.get_world_size(), h.get_world_size());

}

BOOST_AUTO_TEST_CASE(check_game_do_action)
{
  game g = create_test_game_1();
  assert(g.get_bullets().size() == 0);

  //Player 1 (at index 0) shoots one bullet
  g.do_action(0, action::shoot);
  BOOST_CHECK_EQUAL(g.get_bullets().size(), 1);
}

BOOST_AUTO_TEST_CASE(check_game_cannot_shoot_with_absent_player)
{
  game g = create_test_game_1();
  const int absent_player_index = g.get_players().size();

  BOOST_CHECK_THROW(
    g.do_action(absent_player_index, action::shoot),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE(check_game_do_action_accelerate)
{
  game g = create_test_game_1();

  //Player 1 (at index 0) stands still
  assert(g.get_players().front().get_speed_x() == 0.0);
  assert(g.get_players().front().get_speed_y() == 0.0);

  //Player 1 (at index 0) accelerates
  g.do_action(0, action::accelerate);

  BOOST_CHECK(
    g.get_players().front().get_speed_x() != 0.0 ||
    g.get_players().front().get_speed_y() != 0.0
  );

}

BOOST_AUTO_TEST_CASE(check_game_bullets_move)
{
  game g = create_test_game_1();
  g.do_action(1, action::shoot);
  assert(g.get_bullets().size() == 1);
  const auto pos_before = g.get_bullets()[0].get_position();
  g.tick();
  const auto pos_after = g.get_bullets()[0].get_position();
  BOOST_CHECK(pos_before != pos_after);

}

BOOST_AUTO_TEST_CASE(check_game_do_action_decellerate_undoes_accelerate)
{
  game g = create_test_game_1();

  //Player 1 (at index 0) stands still
  assert(g.get_players().front().get_speed_x() == 0.0);
  assert(g.get_players().front().get_speed_y() == 0.0);

  //Player 1 (at index 0) accelerates
  g.do_action(0, action::accelerate);

  assert(
    g.get_players().front().get_speed_x() != 0.0 ||
    g.get_players().front().get_speed_y() != 0.0
  );

  //Player 1 (at index 0) accelerates
  g.do_action(0, action::decelerate);

  BOOST_CHECK(
    g.get_players().front().get_speed_x() == 0.0 &&
    g.get_players().front().get_speed_y() == 0.0
  );

}

BOOST_AUTO_TEST_CASE(check_game_players_turn_speed_changes_with_turn_left)
{
  game g = create_test_game_1();
  const auto turn_speed_before = g.get_players()[0].get_turn_speed();
  g.do_action(0, action::turn_left);
  const auto turn_speed_after = g.get_players()[0].get_turn_speed();
  BOOST_CHECK(turn_speed_before != turn_speed_after);
}

BOOST_AUTO_TEST_CASE(check_game_players_turn_speed_changes_with_turn_right)
{
  game g = create_test_game_1();
  const auto turn_speed_before = g.get_players()[0].get_turn_speed();
  g.do_action(0, action::turn_right);
  const auto turn_speed_after = g.get_players()[0].get_turn_speed();
  BOOST_CHECK(turn_speed_before != turn_speed_after);
}

BOOST_AUTO_TEST_CASE(check_game_player_remains_in_screen)
{
  game g = create_test_game_1();
  g.do_action(0, action::accelerate);
  g.do_action(1, action::accelerate);
  for (int i=0; i!=1000; ++i)
  {
    g.tick();
  }
  BOOST_CHECK(g.get_players()[0].get_x() >= 0.0);
  BOOST_CHECK(g.get_players()[0].get_y() >= 0.0);
  BOOST_CHECK(g.get_players()[0].get_x() < g.get_world_size());
  BOOST_CHECK(g.get_players()[0].get_y() < g.get_world_size());

  BOOST_CHECK(g.get_players()[1].get_x() >= 0.0);
  BOOST_CHECK(g.get_players()[1].get_y() >= 0.0);
  BOOST_CHECK(g.get_players()[1].get_x() < g.get_world_size());
  BOOST_CHECK(g.get_players()[1].get_y() < g.get_world_size());
}

BOOST_AUTO_TEST_CASE(check_game_player_bullets_do_damage)
{
  game g = create_test_game_1();
  const auto hp_before = g.get_players()[0].get_hp();

  g.do_action(0, action::shoot);
  bullet& b = g.get_bullets()[0];
  b.set_position(g.get_players()[0].get_position());
  g.tick();
  const auto hp_after = g.get_players()[0].get_hp();
  BOOST_CHECK_LT(hp_after, hp_before);
}

BOOST_AUTO_TEST_CASE(check_game_players_rotation_changes_after_turning_left)
{
  game g = create_test_game_1();
  g.do_action(0, action::turn_left);
  //Does not turn yet
  assert(g.get_players()[0].get_rotation() == 0.0);
  g.tick();
  BOOST_CHECK_NE(g.get_players()[0].get_rotation(), 0.0);
}

BOOST_AUTO_TEST_CASE(check_game_players_rotation_changes_after_turning_right)
{
  game g = create_test_game_1();
  const auto turn_speed_before = g.get_players()[0].get_turn_speed();
  g.do_action(0, action::turn_right);
  //Does not turn yet
  assert(g.get_players()[0].get_rotation() == 0.0);
  g.tick();
  BOOST_CHECK_NE(g.get_players()[0].get_rotation(), 0.0);
}

BOOST_AUTO_TEST_CASE(check_game_running_at_start)
{
  game g = create_test_game_1();
  BOOST_CHECK(g.get_state() == game_state::running);
}

BOOST_AUTO_TEST_CASE(check_game_over_after_player_one_dies)
{
  game g = create_test_game_1();
  const auto hp_before = g.get_players()[0].get_hp();

  g.do_action(0, action::shoot);
  while (g.get_players()[0].get_hp() > 0.0)
  {
    bullet& b = g.get_bullets()[0];
    b.set_position(g.get_players()[0].get_position());
    g.tick();
  }
  BOOST_CHECK(g.get_state() == game_state::game_over);
}

BOOST_AUTO_TEST_CASE(check_game_do_action_use_power)
{
  game g = create_test_game_1();

  assert(!g.get_players()[0].uses_power());
  g.do_action(0, action::use_power);
  BOOST_CHECK(
    g.get_players()[0].uses_power()
  );
}

BOOST_AUTO_TEST_CASE(check_game_powers_wear_out)
{
  game g = create_test_game_1();
  assert(!g.get_players()[0].uses_power());
  g.do_action(0, action::use_power);
  assert(g.get_players()[0].uses_power());
  for (int i=0; i!=1000; ++i)
  {
    g.tick();
  }
  BOOST_CHECK(!g.get_players()[0].uses_power());
}

BOOST_AUTO_TEST_CASE(power_stop_bullets_actually_stops_bullets)
{
  game g = create_test_game_1();

  //Create bullets
  g.do_action(0, action::shoot);
  g.do_action(1, action::shoot);

  //Both bullets must move
  const auto bullets_before = get_bullets(g);
  BOOST_CHECK_EQUAL(
    2,
    std::count_if(
      std::begin(bullets_before),
      std::end(bullets_before),
      [](const auto& b)
      {
        return is_moving(b);
      }
    )
  );

  //Use the power to stop the bullets
  g.do_action(0, action::use_power);


  //Both bullets must stand still now
  const auto bullets_after = get_bullets(g);
  BOOST_CHECK_EQUAL(
    0,
    std::count_if(
      std::begin(bullets_after),
      std::end(bullets_after),
      [](const auto& b)
      {
        return is_moving(b);
      }
    )
  );

}

