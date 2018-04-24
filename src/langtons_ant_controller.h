#pragma once

#include <SFML/Graphics.hpp>
#include <CAVIS/cavis.h>
#include "langtons_ant_model.h"

class LangtonsAnt : public sf::Drawable, public sf::Transformable {

	unsigned width;
	unsigned height;
	unsigned size;
	unsigned ant_num;

	LangtonsAntModel m;
	ca::Cavis c;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const {

		states.transform *= getTransform();
		target.draw(c, states);
	}

public:

	LangtonsAnt(
		unsigned width,
		unsigned height,
		unsigned size,
		unsigned ant_num
	) :
		width(width),
		height(height),
		size(size),
		ant_num(ant_num),
		m(width, height, ant_num),
		c(width, height, size)
	{}

	void step() {

		m.step();

		for (unsigned y = 0; y != height; ++y) {
			for (unsigned x = 0; x != width; ++x) {
				c[x + (width * y)].setFillColor(
				    m[x + (width * y)]
				    ? sf::Color::Cyan
				    : sf::Color::Black
				);
			}
		}
	}
};


