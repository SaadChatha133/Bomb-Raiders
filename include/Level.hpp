#pragma once

#include <SFML/Graphics.hpp>
#include <vector>


enum class TileType
{
    Empty,
    Wall
};


class Level
{
public:
    static constexpr int TILE_SIZE = 64;
    static constexpr int COLUMNS = 17;
    static constexpr int ROWS = 13;


    Level();


    void draw(sf::RenderWindow& window);

    bool isWalkable(int row, int column) const;


private:
    std::vector<std::vector<TileType>> tiles;

    sf::RectangleShape tileShape;

    void createLevel();
};