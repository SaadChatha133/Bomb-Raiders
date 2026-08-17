#pragma once

#include <SFML/Graphics.hpp>


class Level;


class Player
{
public:
    static constexpr float SPEED = 200.0f;

    Player();

    void update(
        sf::Time deltaTime,
        const Level& level
    );

    void draw(sf::RenderWindow& window);


private:
    sf::RectangleShape playerShape;

    bool canMoveTo(
        sf::Vector2f newPosition,
        const Level& level
    ) const;
};