#pragma once

#include <SFML/Graphics.hpp>


class Player
{
public:
    static constexpr float SPEED = 200.0f;

    Player();

    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);


private:
    sf::RectangleShape playerShape;
};