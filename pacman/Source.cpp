#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "player.h"
#include"ghost.h"
using namespace std;
using namespace sf;

int main()
{
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktopMode, "SFML works!");
	window.setFramerateLimit(30);
	maze maze;
	player player;
	ghost ghost;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		// Draw maze
		maze.draw(window);
		player.drawPlayer(window);
		ghost.draw(window);
		player.checkCollision(maze);
		player.updatePosition();
		
		// display position in the console
		if (Mouse::isButtonPressed(Mouse::Left)) {
			Vector2i pos = Mouse::getPosition(window);
			cout << pos.x << " " << pos.y << endl;
		}
		

		window.display();
	}
	return 0;
}