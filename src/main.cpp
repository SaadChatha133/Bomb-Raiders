#include <SFML/Graphics.hpp>

#include "Level.hpp"
#include "Player.hpp"


void processEvents(sf::RenderWindow& window)
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
    }
}


void update(sf::Time deltaTime, Player& player)
{
    player.update(deltaTime);
}


void render(sf::RenderWindow& window, Level& level, Player& player)
{
    window.clear(sf::Color(30, 30, 30));

    level.draw(window);
    player.draw(window);

    window.display();
}


int main()
{
    sf::RenderWindow window(
        sf::VideoMode({1088, 832}),
        "Bomb Raiders"
    );

    window.setFramerateLimit(30);

    sf::Clock clock;

    Level level;
    Player player;


    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        processEvents(window);

        update(deltaTime, player);

        render(window, level, player);
    }


    return 0;
}