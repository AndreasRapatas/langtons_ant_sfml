#include "langtons_ant.h"

LangtonsAnt::Ant::Ant(unsigned x, unsigned y) :
	x(x),
	y(y),
	direction(Direction::up)
{}

void LangtonsAnt::Ant::turn_right() {

	switch (direction) {

	case Direction::up:
		direction = Direction::right;
		break;
	case Direction::right:
		direction = Direction::down;
		break;
	case Direction::down:
		direction = Direction::left;
		break;
	case Direction::left:
		direction = Direction::up;
		break;
	}
}

void LangtonsAnt::Ant::turn_left() {

	switch (direction) {

	case Direction::up:
		direction = Direction::left;
		break;
	case Direction::right:
		direction = Direction::up;
		break;
	case Direction::down:
		direction = Direction::right;
		break;
	case Direction::left:
		direction = Direction::down;
		break;
	}
}

void LangtonsAnt::Ant::move(unsigned height, unsigned width) {

	// The ternary is used to wrap the ant around the plane.
	// val = val == end of the dimention?
	//		yes: go to the other end
	//		no: actually move

	switch(direction) {

	case Direction::up:
		y = y == height - 1
			? 0
			: y + 1;
		break;
	case Direction::right:
		x = x == width - 1
			? 0
			: x + 1;
		break;
	case Direction::down:
		y = y == 0
			? height - 1
			: y - 1;
		break;
	case Direction::left:
		x = x == 0
			? width - 1
			: x - 1;
		break;
	}
}

LangtonsAnt::LangtonsAnt(unsigned num_of_ants) :
	num_of_ants(num_of_ants)
{}

void LangtonsAnt::initialize_states() {

	for (unsigned i = 0; i != width * height; ++i) {
		state[i] = false;
		next_state[i] = false;
	}
}

void LangtonsAnt::place_ant_randomly() {

	unsigned x_pos = distribution_x(generator);
	unsigned y_pos = distribution_y(generator);

	ants.push_back({x_pos, y_pos});
}

void LangtonsAnt::step() {

	for (unsigned i = 0; i != num_of_ants; ++i) {

		Ant &ant = ants[i];

		next_state(ant.x, ant.y) = !state(ant.x, ant.y);

		if (state(ant.x, ant.y)) {
			ant.turn_right();
		} else {
			ant.turn_left();
		}

		ant.move(height, width);
	}

	state = next_state;
}

sf::Vector2u LangtonsAnt::get_dimentions() {
	return {width, height};
}

void LangtonsAnt::set_dimentions(sf::Vector2u dim) {

	width = dim.x;
	height = dim.y;

	distribution_x = uniform_int_distribution<unsigned>(0, width - 1);
	distribution_y = uniform_int_distribution<unsigned>(0, height - 1);

	state = flat_matrix<bool>(width, height);
	next_state = flat_matrix<bool>(width, height);
	initialize_states();

	ants.clear();
	for (unsigned i = 0; i != num_of_ants; ++i) {
		place_ant_randomly();
	}
}

std::vector<Agent> LangtonsAnt::get_agents() {

	std::vector<Agent> agents;

	for (const auto &ant : ants) {
		agents.emplace_back(ant.x, ant.y, sf::Color(255,0,0));
	}

	return agents;
}

sf::Color LangtonsAnt::get_pixel(unsigned i) {
	return state[i]
		? sf::Color::Cyan
		: sf::Color::Black;
}
