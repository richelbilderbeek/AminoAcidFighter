#include "choose_n_players_menu.h"

#include <stdexcept>

choose_n_players_menu::choose_n_players_menu(const int n_players)
  : m_n_players{n_players}
{
  if (n_players < 2)
  {
    throw std::invalid_argument("Need at least two players");
  }
  if (n_players > 4)
  {
    throw std::invalid_argument("Need at most four players");
  }
}
