#include <iostream>
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>
#include "board_model.h"

using namespace std;
using namespace sf;

int main() {

	// unsigned width = 854; unsigned height = 480;
	unsigned width = 200; unsigned height = 100;

	unsigned cell_num = height * width;

	Board board(width, height, 5);

	RenderWindow window(VideoMode(width, height), "Langton's Ant");
	// window.setVerticalSyncEnabled(true);
	// window.setFramerateLimit(300);

	Texture texture;
	if (!texture.create(width, height)) { exit(1); }
	Sprite sprite;

	uint8_t *pixels = new uint8_t[cell_num * 4];
	if (!pixels) {
		std::cout << "Malloc " << cell_num * sizeof(uint8_t) << " failed!\n";
		exit(1);
	}

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		board.step();

		for (size_t i = 0; i < cell_num; ++i) {
			((uint32_t*)pixels)[i] = board[i] ? 0xFFFFFFFF : 0xFF000000;
		}

		texture.update(pixels);
		sprite.setTexture(texture);

		window.clear();
		window.draw(sprite);
		window.display();
	}

	delete[] pixels;

	return 0;
}
