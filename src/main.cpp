#include <iostream>
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>

#include "langtons_ant.h"
#include <CAVIS/cavis.h>

using namespace std;
using namespace sf;

int main() {

	unsigned width = 200;
	unsigned height = 100;
	unsigned pixel_size = 4;

	LangtonsAnt la(width, height, 1);
	Cavis c(&la, pixel_size);
	c.add_grid(1, Color(50,50,50,255));
	c.add_grid(5, Color(100,100,100,255));
	c.add_grid(10, Color(150,150,150,255));

	RenderWindow window(VideoMode(width * pixel_size, height * pixel_size), "Langton's Ant");
	window.setVerticalSyncEnabled(true);
	sf::Clock clock;

	while (window.isOpen()) {

		double dt = clock.restart().asSeconds();

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear();
		c.handle_user();
		c.update(dt);
		window.draw(c);
		window.display();
	}


	return 0;
}
