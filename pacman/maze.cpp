#include "maze.h"
maze::maze() {
    std::ifstream file("maze_map.txt");
    if (!file.is_open()) {
       
        cout << " File could not be opened, handle error" << endl;
    }

    else{
    maze_map.clear(); // Clear existing maze data

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        for (char c : line) {
            if (c == '1') {
                row.push_back(1);
            }
            else if (c == 'r') {
                row.push_back(2);
            }
            else
                row.push_back(0);
        }
        maze_map.push_back(row);
    }

    file.close();
}
}

bool maze::isWall(int x, int y) {
    return (maze_map[y][x] == 1);
}

bool maze::isPoint(int x, int y) {
    if (x < 0 || x >= maze_map.size() || y < 0 || y >= maze_map[y].size()) {
        return false; 
    }
    return (maze_map[y][x] == 0);
}

void maze::draw(sf::RenderWindow& window) {
    sf::RectangleShape wall;
    wall.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    wall.setFillColor(sf::Color::Blue);
    wall.setOutlineThickness(2);
    wall.setOutlineColor(sf::Color::Red);

    for (int i = 0; i < maze_map.size(); ++i) {
        for (int j = 0; j < maze_map[i].size(); ++j) {
            if (maze_map[i][j] == 1) {
                wall.setPosition(j * CELL_SIZE, i * CELL_SIZE);
                window.draw(wall);
            }
            else if (maze_map[i][j] == 0) {
                sf::CircleShape foodPoint(2);
                foodPoint.setOrigin(2, 2);
                foodPoint.setFillColor(Color{255,182,170});
                foodPoint.setPosition(j * CELL_SIZE+16, i * CELL_SIZE+16);
                window.draw(foodPoint);

            }
        }
    }
}

int maze::getMapSize_y ()
{
    return maze_map.size();
}

int maze::getMapSize_x()
{
    return maze_map[0].size();
}

void maze::pointDisapear(int x, int y) {
    maze_map[y][x] = 2;
}

