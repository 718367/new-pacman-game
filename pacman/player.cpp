#include "player.h"

player::player() : a(1), s(7), d(5), w(3), move_x(0), move_y(0) {
	if (!playerTexture.loadFromFile("spritesheet.png")) {
		cout << "Failed to load spritesheet.png" << std::endl;
	}
	else {
        playerSprite.setTexture(playerTexture);
		playerSprite.setTextureRect(sf::IntRect(0, 0, 26, 26));
		playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
	    playerSprite.setScale(1.15f, 1.15f);
		rect.left = 48;
		rect.top = 48;
	}
	
}



void player::checkWallCollision(maze& maze) {
	float offset = 12;
	// Calculate the grid position of the player's center in the maze
	int playerGridX = static_cast<int>((rect.left + rect.width-35.0 / 2) / CELL_SIZE);
	int playerGridY = static_cast<int>((rect.top + rect.height - 35.0 / 2) / CELL_SIZE);

	// Calculate the grid position of the player's corners with an offset
	 // Adjust the offset as needed
	int rightOffset = static_cast<int>((rect.left + rect.width + offset) / CELL_SIZE);
	int downOffset = static_cast<int>((rect.top + rect.height + offset) / CELL_SIZE);

	// Check for collision with walls at the player's current position and offset positions
	if (maze.isWall(playerGridX, playerGridY) ||
		maze.isWall(rightOffset, playerGridY) ||
		maze.isWall(playerGridX, downOffset) ||
		maze.isWall(rightOffset, downOffset)) {

		// Revert player's position to its previous position
		rect.left -= move_x;
		rect.top -= move_y;

		// Update sprite position
		playerSprite.setPosition(rect.left, rect.top);

		// Reset movement velocities
		move_x = 0;
		move_y = 0;
	}
}

void player::checkPointCollision(maze& maze) {
	// Calculate the grid position of the player's center in the maze
	int playerGridX = static_cast<int>((rect.left + rect.width-10.f / 2) / CELL_SIZE);
	int playerGridY = static_cast<int>((rect.top + rect.height+2.f / 2) / CELL_SIZE);

	// Check for collision with points at the player's current position
	if (maze.isPoint(playerGridX, playerGridY)) {
		// Handle collision with food points
		// Remove the food point from the maze
		maze.pointDisapear(playerGridX, playerGridY);
	}
}


void player::checkCollision(maze& maze)
{
	checkWallCollision(maze);
	checkPointCollision(maze);
}


void player::updatePosition()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		move_x = -5;
		move_y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		move_x = 5;
		move_y = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		move_y = -5;
		move_x = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		move_y = 5;
		move_x = 0;
	}


	// Update player's position based on movement
	rect.left += move_x;
	rect.top += move_y;

	// Check if player has reached boundaries
	if (rect.left < -10) {
		rect.left = 725;
	}
	if (rect.left > 725) {
		rect.left = -10;
	}
	// Update elapsed time
	float deltaTime = clock.restart().asSeconds();

	// Accumulate elapsed frame time
	elapsedFrameTime += deltaTime;
	if (elapsedFrameTime >= frameTime) {

		// Update sprite animation
		updateAnimation();

		elapsedFrameTime = 0.0f;
	}
	// Set player's position
	playerSprite.setPosition(rect.left, rect.top);
}



void player::updateAnimation()
{
	// move right
	if (move_x > 0) {
		d++;
		if (d > 6) {
			d = 5;
		}
		playerSprite.setTextureRect(sf::IntRect(d * 26, 0, 26, 26));
	}
	// move left
	else if (move_x < 0) {
		a++;
		if (a > 2) {
			a = 1;
		}
		playerSprite.setTextureRect(sf::IntRect(a * 26, 0, 26, 26));
	}
	// move up
	if (move_y > 0) {
		s++;
		if (s > 8) {
			s = 7;
		}
		playerSprite.setTextureRect(sf::IntRect(s * 26, 0, 26, 26));
	}
	// move down
	else if (move_y < 0) {
		w++;
		if (w > 4) {
			w = 3;
		}
		playerSprite.setTextureRect(sf::IntRect(w * 26, 0, 26, 26));
	}
}

void player::drawPlayer(RenderWindow& window)
{
	window.draw(playerSprite);
}
