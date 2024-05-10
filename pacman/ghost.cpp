#include "ghost.h"



ghost::ghost() : speed(1), movementInterval(.5),a(1), s(7), d(5), w(3)
{
    ghostPosition.x =400;
    ghostPosition.y = 320;
    if (!ghostTexture.loadFromFile("ghost1.png")) {
        // Handle texture loading failure
    }
    ghostSprite.setTexture(ghostTexture);
    ghostSprite.setTextureRect(sf::IntRect(0, 0,50, 50));
    ghostSprite.setScale(0.9,0.9 );
    ghostSprite.setOrigin(ghostSprite.getLocalBounds().width / 2, ghostSprite.getLocalBounds().height / 2);
    ghostSprite.setPosition(ghostPosition);
}

void ghost::updateAnimation()
{

}


bool ghost::isValidMove(int x, int y, maze& maze) {
    // Check if the position (x, y) is within the bounds of the maze
    if (x >= 0 && x < maze.getMapSize_x() && y >= 0 && y < maze.getMapSize_y()) {
        // Check if the position in the maze map is not a wall ('1')
        if (!maze.isWall(y, x)) {
            return true; // Valid move
        }
    }
    return false; // Invalid move (colliding with wall or out of bounds)
}


void ghost::moveRandomly(maze& maze) {
   
}



void ghost::draw(sf::RenderWindow& window)
{
    window.draw(ghostSprite);
}
