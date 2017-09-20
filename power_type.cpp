#include "power_type.h"

#include "game.h"

int get_duration(const power_type any_power) //!OCLINT cannot make this any shorter
{
  switch (any_power)
  {
    case power_type::ceasefire: return 10;
    case power_type::crash: return 10;
    case power_type::freeze_all: return 10;
    case power_type::freeze_player: return 10;
    case power_type::health: return 10;
    case power_type::homing_missile: return 10;
    case power_type::invisibility: return 10;
    case power_type::invisible_bullets: return 10;
    case power_type::kamikaze: return 10;
    case power_type::maximize: return 10;
    case power_type::mine: return 10;
    case power_type::minimize: return 10;
    case power_type::mix_speed: return 10;
    case power_type::multi_shot: return 10;
    case power_type::opposite_switch: return 10;
    case power_type::power_shot: return 10;
    case power_type::repell: return 10;
    case power_type::reverse_speed: return 10;
    case power_type::reverse_controls: return 10;
    case power_type::shield: return 10;
    case power_type::slowdown: return 10;
    case power_type::spin: return 10;
    case power_type::stop_bullets: return 10;
    case power_type::strafe_left: return 10;
    case power_type::strafe_right: return 10;
    case power_type::switch_players: return 10;
    case power_type::teleport: return 10;
    case power_type::turbo_boost: return 10;
  }
  //Not implemented yet
  return 0;
}

void do_ceasefire(game& g)
{
  std::vector<player> players = get_players(g);
  std::vector<player> new_players;

  for(int i = 0; i != static_cast<int>(players.size()); ++i)
  {
    players[i].unable_to_shoot();
    new_players.push_back(players[i]);
  }
  g.set_players(new_players);
}

void do_health(game &g, const int i)
{
  std::vector<player> players = g.get_players();
  std::vector<player> new_players;

  double current_hp = players[i].get_hp();
  double new_hp = current_hp + 5;
  players[i].set_hp(new_hp);

  for(int j = 0; j != static_cast<int>(players.size()); ++j)
  {
    new_players.push_back(players[j]);
  }

  g.set_players(new_players);
}

void do_kamikaze(game &g)
{
  std::vector<player> players = g.get_players();
  std::vector<player> new_players;

  for(int i = 0; i != static_cast<int>(players.size()); ++i)
  {
    double current_hp = players[i].get_hp();
    double new_hp = current_hp - 5;
    players[i].set_hp(new_hp);
    new_players.push_back(players[i]);
  }
  g.set_players(new_players);
}

void do_mix_speed(game& g)
{
  std::vector<player> players = g.get_players();
  std::vector<player> new_players;

  for(int i = 0; i != static_cast<int>(players.size()); ++i)
  {
    double new_speed_x = players[i].get_speed_y();
    double new_speed_y = players[i].get_speed_x();
    players[i].set_speed_x(new_speed_x);
    players[i].set_speed_y(new_speed_y);
    new_players.push_back(players[i]);
  }
  g.set_players(new_players);
}


void do_opposite_switch(game& g)
{
  std::vector<player> players = g.get_players();
  std::vector<player> new_players;

  for(int i = 0; i != static_cast<int>(players.size()); ++i)
  {
    double rotation = players[i].get_rotation();
    double new_rotation = rotation + 180;
    players[i].set_rotation(new_rotation);
    new_players.push_back(players[i]);
  }
  g.set_players(new_players);
}
void do_reverse_speed(game& g)
{
  std::vector<player> players = g.get_players();
  std::vector<player> new_players;

  for(int i = 0; i != static_cast<int>(players.size()); ++i)
  {
    double new_speed_x = -(players[i].get_speed_x());
    double new_speed_y = -(players[i].get_speed_y());
    players[i].set_speed_x(new_speed_x);
    players[i].set_speed_y(new_speed_y);
    new_players.push_back(players[i]);
  }
  g.set_players(new_players);
}

/*
void do_shield(game& g, const int player_index)
{
  assert(!has_shield(g, player_index));

  g.m_active_powers

  assert(has_shield(g, player_index));
}
*/

void do_slowdown(game& g)
{
  std::vector<player> players = g.get_players();
  std::vector<player> new_players;

  for(int i = 0; i != static_cast<int>(players.size()); ++i)
  {
    double new_speed_x = 0;
    double new_speed_y = 0;
    players[i].set_speed_x(new_speed_x);
    players[i].set_speed_y(new_speed_y);
    new_players.push_back(players[i]);
  }
  g.set_players(new_players);
}

void do_switch_players(game& g)
{
  std::vector<player> players = g.get_players();
  std::vector<player> new_players;
  std::vector<double> x_positions;
  std::vector<double> y_positions;

  for(int i = 0; i != static_cast<int>(players.size()); ++i)
  {
    x_positions.push_back(players[i].get_x());
    y_positions.push_back(players[i].get_y());
  }
  for(int i = 0; i != static_cast<int>(players.size()); ++i)
  {
    if(i != static_cast<int>(players.size()) - 1)
    {
      players[i].set_position(x_positions[i + 1], y_positions[i + 1]);
      new_players.push_back(players[i]);
    }
    else
    {
      players[i].set_position(x_positions[0], y_positions[0]);
      new_players.push_back(players[i]);
    }
  }
  g.set_players(new_players);
}

void do_teleport(game& g, const int i)
{
  std::vector<player> players = g.get_players();
  std::vector<player> new_players;

  players[i].set_position(g.get_world_size() / 2, g.get_world_size() / 2);

  for(int j = 0; j != static_cast<int>(players.size()); ++j)
  {
    new_players.push_back(players[j]);
  }

  g.set_players(new_players);
}

void do_turbo_boost(game& g)
{
  std::vector<player> players = g.get_players();
  std::vector<player> new_players;
  double max_speed_x = 6;
  double max_speed_y = 6;

  for(int i = 0; i != static_cast<int>(players.size()); ++i)
  {
    if((players[i].get_speed_x()) < max_speed_x)
    {
      double new_speed_x = (players[i].get_speed_x()) + 1;
      players[i].set_speed_x(new_speed_x);
    }
    if((players[i].get_speed_y()) < max_speed_y)
    {
      double new_speed_y = (players[i].get_speed_y())+1;
      players[i].set_speed_y(new_speed_y);
    }
    new_players.push_back(players[i]);
  }
  g.set_players(new_players);
}

