#include <cmath>
#include "game.h"

game::game(const std::vector<amino_acid>& )
  : m_world_size{22.0}
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

void game::tick()
{
  for (auto& p: m_players) p.move(m_world_size);
  for (auto& b: m_bullets) b.move();

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
