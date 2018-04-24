#include <iostream>
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>

#include "langtons_ant_controller.h"

using namespace std;
using namespace sf;

int main() {

	unsigned width = 100;
	unsigned height = 50;
	unsigned size = 10;

	LangtonsAnt la(width, height, size, 2);

	RenderWindow window(VideoMode(width * size, height * size), "Langton's Ant");
	window.setVerticalSyncEnabled(true);

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		la.step();

		window.clear();
		window.draw(la);
		window.display();
	}


	return 0;
}
