#include "power.h"

#include "game.h"

int get_duration(const power any_power) //!OCLINT cannot make this any shorter
{
  switch (any_power)
  {
    case power::ceasefire: return 10;
    case power::crash: return 10;
    case power::freeze_all: return 10;
    case power::freeze_player: return 10;
    case power::health: return 10;
    case power::homing_missile: return 10;
    case power::invisibility: return 10;
    case power::invisible_bullets: return 10;
    case power::kamikaze: return 10;
    case power::maximize: return 10;
    case power::mine: return 10;
    case power::minimize: return 10;
    case power::mix_speed: return 10;
    case power::multi_shot: return 10;
    case power::opposite_switch: return 10;
    case power::power_shot: return 10;
    case power::repell: return 10;
    case power::reverse_speed: return 10;
    case power::reverse_controls: return 10;
    case power::shield: return 10;
    case power::slowdown: return 10;
    case power::spin: return 10;
    case power::stop_bullets: return 10;
    case power::strafe_left: return 10;
    case power::strafe_right: return 10;
    case power::switch_players: return 10;
    case power::teleport: return 10;
    case power::turbo_boost: return 10;
  }
  //Not implemented yet
  return 0;
}

void do_power(power any_power, game& g) //!OCLINT cannot make this any shorter
{
  switch (any_power)
  {
    case power::ceasefire        : /*do_ceasefire(g)       */ ; break;
    case power::crash            : /*do_crash()            */; break;
    case power::freeze_all       : /*do_freeze_all()       */; break;
    case power::freeze_player    : /*do_freeze_player()    */; break;
    case power::health           : /*do_health()           */; break;
    case power::homing_missile   : /*do_homing_missle()    */; break;
    case power::invisibility     : /*do_invisibility()     */; break;
    case power::invisible_bullets: /*do_invisible_bullets()*/; break;
    case power::kamikaze         : /*do_kamikaze()        */ ; break;
    case power::maximize         : /*do_maximize()        */ ; break;
    case power::mine             : /*do_mine()            */ ; break;
    case power::minimize         : /*do_minimize()        */ ; break;
    case power::mix_speed        : do_mix_speed(g)        ; break;
    case power::multi_shot       : /*do_multi_shot()      */ ; break;
    case power::opposite_switch  : /*do_opposite_switch() */ ; break;
    case power::power_shot       : /*do_power_shot()      */ ; break;
    case power::repell           : /*do_repell()          */ ; break;
    case power::reverse_speed    : do_reverse_speed(g)    ; break;
    case power::reverse_controls : /*do_reverse_controls()*/ ; break;
    case power::shield           : /*do_shield()         */  ; break;
    case power::slowdown         : do_slowdown(g)         ; break;
    case power::spin             : /*do_spin()           */  ; break;
    case power::stop_bullets     : do_stop_bullets(g)     ; break;
    case power::strafe_left      : /*do_strafe_left()    */  ; break;
    case power::strafe_right     : /*do_strafe_right()    */ ; break;
    case power::switch_players   : do_switch_players(g)    ; break;
    case power::teleport         : do_teleport(g)         ; break;
    case power::turbo_boost      : /*do_turbo_boost()*/      ; break;
  }
  //Not implemented yet
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

void do_stop_bullets(game& g)
{
  std::vector<bullet> bullets = g.get_bullets();
  std::vector<bullet> new_bullets;
  for(int i=0; i < static_cast<int>(bullets.size()); ++i)
  {
    bullets[i].set_speed_x_zero();
    bullets[i].set_speed_y_zero();
    new_bullets.push_back(bullets[i]);
  }
  g.set_bullets(new_bullets);
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

void do_teleport(game& g)
{
  std::vector<player> players = g.get_players();
  std::vector<player> new_players;

  for(int i = 0; i != static_cast<int>(players.size()); ++i)
  {
      players[i].set_position(g.get_world_size() / 2, g.get_world_size() / 2);
      new_players.push_back(players[i]);
  }
  g.set_players(new_players);
}
