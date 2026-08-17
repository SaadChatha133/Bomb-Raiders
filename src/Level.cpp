#include "Level.hpp"


Level::Level()
{
    createLevel();
}


void Level::createLevel()
{
    tiles.resize(
        ROWS,
        std::vector<TileType>(
            COLUMNS,
            TileType::Empty
        )
    );


    // Create the outer walls.
    for (int row = 0; row < ROWS; ++row)
    {
        for (int column = 0; column < COLUMNS; ++column)
        {
            if (row == 0 ||
                row == ROWS - 1 ||
                column == 0 ||
                column == COLUMNS - 1)
            {
                tiles[row][column] = TileType::Wall;
            }
        }
    }
}


bool Level::isWalkable(int row, int column) const
{
    // Outside the level is never walkable.
    if (row < 0 ||
        row >= ROWS ||
        column < 0 ||
        column >= COLUMNS)
    {
        return false;
    }


    return tiles[row][column] == TileType::Empty;
}


void Level::draw(sf::RenderWindow& window)
{
    for (int row = 0; row < ROWS; ++row)
    {
        for (int column = 0; column < COLUMNS; ++column)
        {
            if (tiles[row][column] == TileType::Wall)
            {
                tileShape.setSize(
                    sf::Vector2f(
                        static_cast<float>(TILE_SIZE),
                        static_cast<float>(TILE_SIZE)
                    )
                );


                tileShape.setPosition(
                    sf::Vector2f(
                        static_cast<float>(column * TILE_SIZE),
                        static_cast<float>(row * TILE_SIZE)
                    )
                );


                tileShape.setFillColor(
                    sf::Color(80, 80, 80)
                );


                window.draw(tileShape);
            }
        }
    }
}