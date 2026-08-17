#include <cmath>

#include "Player.hpp"
#include "Level.hpp"


Player::Player()
{
    playerShape.setSize(
        sf::Vector2f(48.0f, 48.0f)
    );


    playerShape.setFillColor(
        sf::Color(50, 150, 250)
    );


    // Start inside the first walkable tile.
    playerShape.setPosition(
        sf::Vector2f(72.0f, 72.0f)
    );
}


bool Player::canMoveTo(
    sf::Vector2f newPosition,
    const Level& level
) const
{
    sf::FloatRect playerBounds(
        newPosition,
        playerShape.getSize()
    );


    // Find the tiles occupied by the player's rectangle.
    int leftColumn =
        static_cast<int>(
            playerBounds.position.x
            / Level::TILE_SIZE
        );

    int rightColumn =
        static_cast<int>(
            (playerBounds.position.x +
             playerBounds.size.x - 0.01f)
            / Level::TILE_SIZE
        );

    int topRow =
        static_cast<int>(
            playerBounds.position.y
            / Level::TILE_SIZE
        );

    int bottomRow =
        static_cast<int>(
            (playerBounds.position.y +
             playerBounds.size.y - 0.01f)
            / Level::TILE_SIZE
        );


    // Check every tile touched by the player.
    for (int row = topRow;
         row <= bottomRow;
         ++row)
    {
        for (int column = leftColumn;
             column <= rightColumn;
             ++column)
        {
            if (!level.isWalkable(row, column))
            {
                return false;
            }
        }
    }


    return true;
}


void Player::update(
    sf::Time deltaTime,
    const Level& level
)
{
    float movement =
        SPEED * deltaTime.asSeconds();

    sf::Vector2f direction(0.0f, 0.0f);


    // Vertical movement
    if (sf::Keyboard::isKeyPressed(
            sf::Keyboard::Key::W) ||
        sf::Keyboard::isKeyPressed(
            sf::Keyboard::Key::Up))
    {
        direction.y -= 1.0f;
    }

    if (sf::Keyboard::isKeyPressed(
            sf::Keyboard::Key::S) ||
        sf::Keyboard::isKeyPressed(
            sf::Keyboard::Key::Down))
    {
        direction.y += 1.0f;
    }


    // Horizontal movement
    if (sf::Keyboard::isKeyPressed(
            sf::Keyboard::Key::A) ||
        sf::Keyboard::isKeyPressed(
            sf::Keyboard::Key::Left))
    {
        direction.x -= 1.0f;
    }

    if (sf::Keyboard::isKeyPressed(
            sf::Keyboard::Key::D) ||
        sf::Keyboard::isKeyPressed(
            sf::Keyboard::Key::Right))
    {
        direction.x += 1.0f;
    }


    // Normalize diagonal movement.
    if (direction.x != 0.0f &&
        direction.y != 0.0f)
    {
        direction /= std::sqrt(2.0f);
    }


    sf::Vector2f currentPosition =
        playerShape.getPosition();


    // Try horizontal movement.
    if (direction.x != 0.0f)
    {
        sf::Vector2f newPosition(
            currentPosition.x +
                direction.x * movement,
            currentPosition.y
        );

        if (canMoveTo(newPosition, level))
        {
            currentPosition.x = newPosition.x;
        }
    }


    // Try vertical movement.
    if (direction.y != 0.0f)
    {
        sf::Vector2f newPosition(
            currentPosition.x,
            currentPosition.y +
                direction.y * movement
        );

        if (canMoveTo(newPosition, level))
        {
            currentPosition.y = newPosition.y;
        }
    }


    playerShape.setPosition(currentPosition);
}


void Player::draw(sf::RenderWindow& window)
{
    window.draw(playerShape);
}