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

void do_power(power_type any_power, game& g) //!OCLINT cannot make this any shorter
{
  switch (any_power)
  {
    case power_type::ceasefire        : /*do_ceasefire(g)       */ ; break;
    case power_type::crash            : /*do_crash()            */; break;
    case power_type::freeze_all       : /*do_freeze_all()       */; break;
    case power_type::freeze_player    : /*do_freeze_player()    */; break;
    case power_type::health           : do_health(g)           ; break;
    case power_type::homing_missile   : /*do_homing_missle()    */; break;
    case power_type::invisibility     : /*do_invisibility()     */; break;
    case power_type::invisible_bullets: /*do_invisible_bullets()*/; break;
    case power_type::kamikaze         : do_kamikaze(g)         ; break;
    case power_type::maximize         : /*do_maximize()        */ ; break;
    case power_type::mine             : /*do_mine()            */ ; break;
    case power_type::minimize         : /*do_minimize()        */ ; break;
    case power_type::mix_speed        : do_mix_speed(g)        ; break;
    case power_type::multi_shot       : /*do_multi_shot()      */ ; break;
    case power_type::opposite_switch  : do_opposite_switch(g)  ; break;
    case power_type::power_shot       : /*do_power_shot()      */ ; break;
    case power_type::repell           : /*do_repell()          */ ; break;
    case power_type::reverse_speed    : do_reverse_speed(g)    ; break;
    case power_type::reverse_controls : /*do_reverse_controls()*/ ; break;
    case power_type::shield           : /*do_shield()         */  ; break;
    case power_type::slowdown         : do_slowdown(g)         ; break;
    case power_type::spin             : /*do_spin()           */  ; break;
    case power_type::stop_bullets     : do_stop_bullets(g)     ; break;
    case power_type::strafe_left      : /*do_strafe_left()    */  ; break;
    case power_type::strafe_right     : /*do_strafe_right()    */ ; break;
    case power_type::switch_players   : do_switch_players(g)   ; break;
    case power_type::teleport         : do_teleport(g)         ; break;
    case power_type::turbo_boost      : do_turbo_boost(g)      ; break;
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

void do_health(game &g)
{
  std::vector<player> players = g.get_players();
  std::vector<player> new_players;

  for(int i = 0; i != static_cast<int>(players.size()); ++i)
  {
    double current_hp = players[i].get_hp();
    double new_hp = current_hp + 5;
    players[i].set_hp(new_hp);
    new_players.push_back(players[i]);
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
