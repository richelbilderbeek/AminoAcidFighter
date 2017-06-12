#include "game.h"

#include <cmath>
#include <stdexcept>
#include "player.h"

game::game(
  const std::vector<amino_acid>& amino_acids,
  const int world_size,
  const bool do_play_music,
  const bool is_profile_run
)
  : m_bullets{},
    m_do_play_music{do_play_music},
    m_game_state{game_state::running},
    m_is_profile_run{is_profile_run},
    m_players{create_players(amino_acids, world_size)},
    m_state{program_state::battle},
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
  const int world_size{314};
  std::vector<amino_acid> amino_acids =
  {
    amino_acid::tyrosine,
    amino_acid::glycine
  };
  const bool do_play_music{false};
  const bool is_profile_run{false};
  return game{amino_acids, world_size, do_play_music, is_profile_run};
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
    m_players[i].start_using_power(*this);
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

std::vector<amino_acid> get_amino_acids(const game& g)
{
  std::vector<player> ps = g.get_players();
  std::vector<amino_acid> aas;
  for(int i = 0; i != static_cast<int>(ps.size()); ++i)
  {
    aas.push_back(ps[i].get_amino_acid());
  }
  return aas;
}

const std::vector<bullet>& get_bullets(const game& g)
{
  return g.get_bullets();
}

std::vector<bullet>& get_bullets(game& g)
{
  return g.get_bullets();
}

bool get_do_play_music(const game& g)
{
  return g.get_do_play_music();
}

bool get_is_profile_run(const game& g)
{
  return g.get_is_profile_run();
}

const std::vector<player>& get_players(const game& g)
{
  return g.get_players();
}

std::vector<player>& get_players(game& g)
{
  return g.get_players();
}

program_state get_state(const game& g)
{
  return g.get_state();
}

void game::tick()
{
  if(get_game_state() == game_state::running)
  {
    for (auto& p: m_players) p.move(m_world_size);
    for (auto& b: m_bullets)
    {
      b.move(m_world_size);
      b.slow_down();
    }
    bullet_hits_player();
    remove_dead_bullets(m_bullets);
    for (auto i{0u}; i < m_players.size(); ++i)
    {
      m_players[i].stops_using_power(*this);
    }
    do_damage();
    if(m_players[0].get_hp() <= 0.0)
    {
      m_game_state = game_state::game_over;
    }
  }
}

void set_state(game& g, program_state p)
{
  g.set_state(p);
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
