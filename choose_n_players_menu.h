#ifndef CHOOSE_N_PLAYERS_MENU_H
#define CHOOSE_N_PLAYERS_MENU_H

///Menu to select the number of players
class choose_n_players_menu
{
public:
  ///The initial number of players
  choose_n_players_menu(const int n_players = 2);

  ///Will remain 2 if 2
  void decrease() noexcept;

  ///Will remain 4 if 4
  void increase() noexcept;

  ///Get the number of players
  int get_n_player() const noexcept { return m_n_players; }

private:

  int m_n_players;
};

#endif // CHOOSE_N_PLAYERS_MENU_H
