#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "maze.h"

using namespace std;
using namespace sf;
#pragma once
class player
{
private:
	int a, s, d, w;
	float move_x, move_y;
	float frameTime = 0.07f; 
	float elapsedFrameTime = 0.0f;
	FloatRect rect;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Clock clock;
	void updateAnimation();
public:
	// Constructor
	player();
	void updatePosition();
	void drawPlayer(RenderWindow& window);
	void checkCollision(maze& maze);
	void checkWallCollision(maze& maze);
	void checkPointCollision(maze& maze);
};

