#include "../include/Map.h"
#include <iostream>

Map::Map(int rows, int cols, int tileSize, const Texture texture1, const Texture texture2) : rows(rows), cols(cols), tileSize(tileSize), texture1(texture1), texture2(texture2) {
    for (int i = 0; i < rows; ++i) {
        std::vector<Sprite> rowSprite;
        for (int j = 0; j < cols; ++j) {
            sf::Sprite tileSprite;
            tileSprite.setTexture(this->texture1);  // Default to texture1
            
            // Set a 50x50 section of the texture to match the tile size
            tileSprite.setTextureRect(sf::IntRect(0, 0, tileSize, tileSize));

            tileSprite.setPosition(j * tileSize, i * tileSize);
            rowSprite.push_back(tileSprite);
        }
        grid.push_back(rowSprite);
    }
}
Map::~Map() {}
void Map::draw(sf::RenderWindow& window) {
    for (const auto& row : grid) {
        for (const auto& tile : row) {
            if (tile.getTexture() == nullptr) {
                std::cerr << "Error: Tile has no texture!" << std::endl;
            }
            window.draw(tile);
        }
    }
}
void Map::setTile(int row, int col, int textureType) {
    if (row >= 0 && col >= 0 && row < rows && col < cols) {
        switch (textureType) {
            case 1:
                grid[row][col].setTexture(texture1);
                grid[row][col].setTextureRect(sf::IntRect(0, 0, tileSize, tileSize));  // Ensure 50x50 portion
                break;
            case 2:
                grid[row][col].setTexture(texture2);
                grid[row][col].setTextureRect(sf::IntRect(0, 0, tileSize, tileSize));  // Ensure 50x50 portion
                break;
        }

    }
}