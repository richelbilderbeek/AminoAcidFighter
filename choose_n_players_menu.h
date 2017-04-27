#ifndef CHOOSE_N_PLAYERS_MENU_H
#define CHOOSE_N_PLAYERS_MENU_H

///Menu to select the number of players
class choose_n_players_menu
{
public:
  ///@param n_players The initial number of players, must be in range [2, 4]
  choose_n_players_menu(const int n_players = 2);

  ///Will remain 2 if 2
  void decrease() noexcept { m_n_players = m_n_players == 2 ? 2 : m_n_players - 1; }

  ///Will remain 4 if 4
  void increase() noexcept { m_n_players = m_n_players == 4 ? 4 : m_n_players + 1; }

  ///Get the number of players
  int get_n_player() const noexcept { return m_n_players; }

private:
  int m_n_players;
};

#endif // CHOOSE_N_PLAYERS_MENU_H
