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

	LangtonsAnt la(width, height, 1);
	Cavis c(&la);

	RenderWindow window(VideoMode(width, height), "Langton's Ant");
	window.setVerticalSyncEnabled(true);
	sf::Clock clock;

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear();
		c.update(clock.restart().asSeconds());
		window.draw(c);
		window.display();
	}


	return 0;
}
