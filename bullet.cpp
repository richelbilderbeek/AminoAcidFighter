#include "bullet.h"



bullet::bullet(
        const double speed,
        const double damage,
        const sf::Color color,
        const double size,
        const sf::Vector2f position)
    :
    m_speed{speed},
    m_damage{damage},
    m_color{color},
    m_size{size},
    m_position{position}
{}

void bullet::set_position(sf::Vector2f position)
{
    m_position = position;
}

bullet create_bullet(sf::Vector2f position)
{
    return bullet(10,5,sf::Color::Red,10, position);
}

sf::CircleShape get_shape(const bullet& bullet)
{
    sf::CircleShape bullet_shape;
    bullet_shape.setRadius(bullet.get_size());
    bullet_shape.setPosition(bullet.get_position());
    bullet_shape.setFillColor(bullet.get_color());
    return bullet_shape;
}
