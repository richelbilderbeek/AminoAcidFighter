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

std::vector<double> collect_player_speed_xs(const game& g)
{
  std::vector<double> speed_xs;
  const auto ps = get_players(g);
  speed_xs.reserve(ps.size());
  std::transform(
    std::begin(ps),
    std::end(ps),
    std::back_inserter(speed_xs),
    [](const auto& p) { return p.get_speed_x(); }
  );
  return speed_xs;
}

std::vector<double> collect_player_speed_ys(const game& g)
{
  std::vector<double> speed_ys;
  const auto ps = get_players(g);
  speed_ys.reserve(ps.size());
  std::transform(
    std::begin(ps),
    std::end(ps),
    std::back_inserter(speed_ys),
    [](const auto& p) { return p.get_speed_y(); }
  );
  return speed_ys;
}

int count_bullets(const game& g) noexcept
{
  std::vector<bullet> bullets = get_bullets(g);
  return bullets.size();
}

int count_moving_bullets(const game& g) noexcept
{
  std::vector<bullet> bullets = get_bullets(g);
  return std::count_if(
    std::begin(bullets),
    std::end(bullets),
    [](const bullet& b)
    {
      return b.get_speed_x() != 0.0 || b.get_speed_y() != 0.0;
    }
  );
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

game create_test_game_2()
{
  const int world_size{640};
  std::vector<amino_acid> amino_acids =
  {
    amino_acid::aspartic_acid,
    amino_acid::glutamic_acid,
    amino_acid::phenylalanine,
    amino_acid::tryptophan
  };
  const bool do_play_music{false};
  const bool is_profile_run{false};
  game g{amino_acids, world_size, do_play_music, is_profile_run};
  for (int i{0}; i!=4; ++i)
  {
    g.do_action(i, action::accelerate);
    g.do_action(i, action::turn_left);
    g.do_action(i, action::shoot);
  }
  g.tick();
  return g;
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
    if(m_players[i].get_shoot_ability() == true)
    {
      m_bullets.push_back(shoot(m_players[i]));
    }
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

std::vector<amino_acid> get_amino_acids(const game& g)
{
  const auto ps = g.get_players();
  std::vector<amino_acid> aas;
  aas.reserve(ps.size());
  std::transform(
    std::begin(ps),
    std::end(ps),
    std::back_inserter(aas),
    [](const auto& player)
    {
      return player.get_amino_acid();
    }
  );
  /* Old, for educational value
  std::vector<player> ps = g.get_players();
  std::vector<amino_acid> aas;
  for(int i = 0; i != static_cast<int>(ps.size()); ++i)
  {
    aas.push_back(ps[i].get_amino_acid());
  }
  */
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
    do_damage();
    remove_dead_bullets(m_bullets);

    for (auto i{0u}; i < m_players.size(); ++i)
    {
      m_players[i].stops_using_power(*this);
    }
    do_damage();

    /*if(m_players[0].get_hp() <= 0.0)
    {
      m_game_state = game_state::game_over;
    }*/
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

bool operator==(const game& lhs, const game& rhs) noexcept
{
  return lhs.get_bullets() == rhs.get_bullets()
    && lhs.get_do_play_music() == rhs.get_do_play_music()
    && lhs.get_game_state() == rhs.get_game_state()
    && lhs.get_is_profile_run() == rhs.get_is_profile_run()
    && lhs.get_players() == rhs.get_players()
    && lhs.get_state() == rhs.get_state()
    && lhs.get_world_size() == rhs.get_world_size();
}
