#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

using namespace std;
using namespace sf;


#ifndef MAZE_H
#define MAZE_H

const int MAZE_ROW = 24;
const int MAZE_COLUMN = 21;
const int CELL_SIZE = 30;

class maze {
private:
    std::vector<std::vector<int>> maze_map;

public:
    maze();
    bool isWall(int x, int y);
    bool isPoint(int x, int y);
    void draw(sf::RenderWindow& window);
    int getMapSize_y();
    int getMapSize_x();

    void pointDisapear(int x, int y);
};

#endif // MAZE_H