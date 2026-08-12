#include "Player.hpp"


Player::Player()
{
    playerShape.setSize(
        sf::Vector2f(48.0f, 48.0f)
    );

    playerShape.setFillColor(
        sf::Color(50, 150, 250)
    );

    // Start the player inside the top-left area
    // of the level.
    playerShape.setPosition(
        sf::Vector2f(96.0f, 96.0f)
    );
}


void Player::update(sf::Time deltaTime)
{
    float movement = SPEED * deltaTime.asSeconds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        playerShape.move(
            sf::Vector2f(0.0f, -movement)
        );
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        playerShape.move(
            sf::Vector2f(0.0f, movement)
        );
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        playerShape.move(
            sf::Vector2f(-movement, 0.0f)
        );
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        playerShape.move(
            sf::Vector2f(movement, 0.0f)
        );
    }
}


void Player::draw(sf::RenderWindow& window)
{
    window.draw(playerShape);
}