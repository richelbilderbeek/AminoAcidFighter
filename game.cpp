#include "game.h"

#include <cmath>
#include <stdexcept>
#include "player.h"

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

void game::bullet_hits_player()
{
  for(auto& player: m_players)
  {
    for(auto& bullet: m_bullets)
    {
      const auto distance = calculate_distance(bullet, player);
      if(distance <= get_hit_range_size())
      {
        player.lose_hp();
        bullet.slow_down();
      }
    }
  }
}

double calculate_distance(const bullet& b, const player& p)
{
  const auto delta_x = b.get_x() - p.get_x();
  const auto delta_y = b.get_y() - p.get_y();
  return std::sqrt((delta_x * delta_x) + (delta_y * delta_y));
}

std::vector<double> collect_hit_points(const game& g)
{
  std::vector<double> hps;
  const auto ps = get_players(g);
  hps.reserve(ps.size());
  std::transform(
    std::begin(ps),
    std::end(ps),
    std::back_inserter(hps),
    [](const auto& p) { return p.get_hp(); }
  );
  return hps;
}

std::vector<player> create_players(
  const std::vector<amino_acid>& amino_acids,
  const int world_size
)
{
  std::vector<player> p;
  const std::vector<double> xs =
  {
    world_size * 0.25, world_size * 0.75, world_size * 0.25, world_size * 0.75
  };
  const std::vector<double> ys =
  {
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
  std::vector<amino_acid> amino_acids =
  {
    amino_acid::tyrosine,
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
      double distance = calculate_distance(m_bullets[j], m_players[i]);
      if(distance < get_hit_range_size())
      {
        m_players[i].lose_hp();
      }
    }
  }
}

const std::vector<bullet>& get_bullets(const game& g)
{
  return g.get_bullets();
}

std::vector<bullet>& get_bullets(game& g)
{
  return g.get_bullets();
}

const std::vector<player>& get_players(const game& g)
{
  return g.get_players();
}

std::vector<player>& get_players(game& g)
{
  return g.get_players();
}

void game::tick()
{
  if(get_state() == game_state::running)
  {
    bullet_hits_player();
    for (auto& p: m_players) p.move(m_world_size);
    for (auto& b: m_bullets)
    {
      b.move(m_world_size);
      b.slow_down();
    }
    for (auto i{0u}; i < m_players.size(); ++i)
    {
      m_players[i].stops_using_power();
    }
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
