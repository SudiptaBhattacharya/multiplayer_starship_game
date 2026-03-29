#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

class Map {
    public:
        Map(int rows, int cols, int tileSize, const Texture texture1, const Texture texture2);
        ~Map();
        void draw(RenderWindow& window);
        void setTile(int row, int col, int textureType);
    private:
        int rows, cols, tileSize;
        std::vector<std::vector<Sprite>> grid;
        const Texture texture1;
        const Texture texture2;
};

#endif