#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "maze.h"

using namespace std;
using namespace sf;

class ghost
{
private:
    int a, s, d, w;
    sf::Vector2f ghostPosition;
    sf::Texture ghostTexture;
    sf::Sprite ghostSprite;
    sf::Clock movementClock;
    float speed; float movementInterval; // Interval between movements
   

public:
    ghost();

    void updateAnimation();

    // Function to check if a position is a valid movement location (not colliding with walls)
    bool isValidMove(int x, int y,  maze& maze);

    void moveRandomly( maze& maze); // Declaration of moveRandomly function

    void draw(sf::RenderWindow& window); // Public method to draw ghost on screen
};

