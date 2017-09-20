#include "power.h"

#include <cassert>
#include "game.h"

power::power(
  int end_frame,
  int player_index,
  power_type type
)
  : m_endframe{end_frame},
    m_player_index{player_index},
    m_type{type}
{}

#ifdef THINK_THIS_IS_A_GREAT_IDEA_20170920
void do_power(power_type t, game &g, const int player_index) //!OCLINT cannot make this any shorter
{
  //Cannot do a power while using a power
  assert(!get_player(g, player_index).is_using_power());
  switch (t)
  {
    case power_type::ceasefire        : /*do_ceasefire(g)       */ ; break;
    case power_type::crash            : /*do_crash()            */; break;
    case power_type::freeze_all       : /*do_freeze_all()       */; break;
    case power_type::freeze_player    : /*do_freeze_player()    */; break;
    case power_type::health           : do_health(g, player_index)           ; break;
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
    case power_type::shield           : do_shield(g, player_index); break;
    case power_type::slowdown         : do_slowdown(g)         ; break;
    case power_type::spin             : /*do_spin()           */  ; break;
    case power_type::stop_bullets     : do_stop_bullets(g)     ; break;
    case power_type::strafe_left      : /*do_strafe_left()    */  ; break;
    case power_type::strafe_right     : /*do_strafe_right()    */ ; break;
    case power_type::switch_players   : do_switch_players(g)   ; break;
    case power_type::teleport         : do_teleport(g, player_index)         ; break;
    case power_type::turbo_boost      : do_turbo_boost(g)      ; break;
  }
  assert(get_player(g, player_index).is_using_power());
  //Not implemented yet
}
#endif // THINK_THIS_IS_A_GREAT_IDEA_20170920
