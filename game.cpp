#include <cmath>
#include <stdexcept>
#include "game.h"

game::game(
  const std::vector<amino_acid>& amino_acids,
  const double world_size
)
  : m_bullets{},
    m_players{create_players(amino_acids, world_size)},
    m_state{game_state::running},
    m_world_size{world_size}
{
}

float calculate_distance_bullet_player(bullet any_bullet, player any_player)
{
  const float bullet_position_x = any_bullet.get_x();
  const float bullet_position_y = any_bullet.get_y();
  const float player_position_x = any_player.get_x();
  const float player_position_y = any_player.get_y();

  const float length_x = bullet_position_x - player_position_x;
  const float length_y = bullet_position_y - player_position_y;
  const float x2 = length_x * length_x;
  const float y2 = length_y * length_y;
  const float a2 = x2 + y2;
  return sqrt(a2);
}

std::vector<player> create_players(
  const std::vector<amino_acid>& amino_acids,
  const double world_size
)
{
  std::vector<player> p;
  const std::vector<double> xs = {
    world_size * 0.25, world_size * 0.75, world_size * 0.25, world_size * 0.75
  };
  const std::vector<double> ys = {
    world_size * 0.25, world_size * 0.25, world_size * 0.75, world_size * 0.75
  };
  const auto sz = amino_acids.size();
  for (auto i = 0u; i!=sz; ++i)
  {
    p.push_back(player(amino_acids[i], xs[i], ys[i]));
  }
  return p;
}

game create_test_game_1()
{
  const double world_size{314.159};
  const std::vector<amino_acid> amino_acids =
  {
    amino_acid::alanine,
    amino_acid::glycine
  };
  return game{amino_acids, world_size};
}

void game::do_action(int i, action any_action)
{
  if(i < 0 || i >= static_cast<int>(m_players.size()))
  {
    throw std::invalid_argument("This player does not exist");
  }
  if(any_action == action::accelerate)
  {
    m_players[i].accelerate();
  }
  if(any_action == action::decelerate)
  {
    m_players[i].decelerate();
  }
  if(any_action == action::shoot)
  {
    m_bullets.push_back(shoot(m_players[i]));
  }
  if(any_action == action::turn_left)
  {
    m_players[i].turn_left();
  }
  if(any_action == action::turn_right)
  {
    m_players[i].turn_right();
  }
  if(any_action == action::use_power)
  {
    m_players[i].start_using_power();
  }
}

void game::do_damage()
{
  for(auto i{0u}; i < m_players.size(); ++i)
  {
    for(auto j{0u}; j < m_bullets.size(); ++j)
    {
      double distance = calculate_distance_bullet_player(m_bullets[j], m_players[i]);
      if(distance < get_hit_range_size())
      {
        m_players[i].lose_hp();
      }
    }
  }
}

void game::tick()
{
  if(get_state() == game_state::running)
  {
    for (auto& p: m_players) p.move(m_world_size);
    for (auto& b: m_bullets) b.move();
    do_damage();
    if(m_players[0].get_hp() <= 0.0)
    {
      m_state = game_state::game_over;
    }
  }
}

std::ostream& operator<<(std::ostream& os, const game& g) noexcept
{
  os << "Players:\n";
  for (const auto& p: g.get_players())
  {
    os << p << '\n';
  }
  os << "Bullets:\n";
  for (const auto& b: g.get_bullets())
  {
    os << b << '\n';
  }
  os << "World size:\n";
  os << g.get_world_size();
  return os;
}
