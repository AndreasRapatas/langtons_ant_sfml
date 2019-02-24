#ifndef LANGTONS_ANT_H
#define LANGTONS_ANT_H

#include <vector>
#include <random>

#include <flat_matrix/flat_matrix.h>

#include "CAVIS/cellular_automaton.h"

using namespace std;

class LangtonsAnt : public CellularAutomaton {

private:

	struct Ant {

		enum class Direction {
			up, right, down, left
		};

		unsigned x;
		unsigned y;
		Direction direction;

		Ant() = default;
		Ant(unsigned x, unsigned y);

		void turn_right();
		void turn_left();
		void move(unsigned height, unsigned width);
	};

	unsigned width;
	unsigned height;
	unsigned num_of_ants;
	vector<Ant> ants;
	flat_matrix<bool> state;
	flat_matrix<bool> next_state;

	default_random_engine generator;
	uniform_int_distribution<unsigned> distribution_x;
	uniform_int_distribution<unsigned> distribution_y;

	void initialize_states();

	void place_ant_randomly();

public:

	LangtonsAnt(unsigned num_of_ants);

	void step();

	sf::Vector2u get_dimentions();

	void set_dimentions(sf::Vector2u dim);

	std::vector<Agent> get_agents();

	sf::Color get_pixel(unsigned i);
};

#endif // LANGTONS_ANT_H
