# Langton's Ant
This project implements [Langton's Ant](https://en.wikipedia.org/wiki/Langton%27s_ant) on a torus using C++ and displays it using [Rapatas/CAVIS](https://github.com/Rapatas/CAVIS). Langton's Ant is a [cellular automaton](https://en.wikipedia.org/wiki/Cellular_automaton) with a complex emergent behavior but very simple set of rules:
* At a white square, turn 90° right, flip the color of the square, move forward one unit
* At a black square, turn 90° left, flip the color of the square, move forward one unit

# Enjoy 3 ants on a torus:
```bash
langtons_ant_sfml --ants 3 --height 100
```

![Preview](https://i.imgur.com/348YuU3.gif "3 ants on a torus")

# Installation
## Dependencies
Follow the project's installation instructions.
* [Rapatas/flat_matrix](https://github.com/Rapatas/flat_matrix)
* [Rapatas/CAVIS](https://github.com/Rapatas/CAVIS)
* [Taywee/args](https://github.com/Taywee/args)

## Langton's Ant
```bash
git clone https://github.com/Rapatas/langtons_ant_sfml
mkdir langtons_ant_sfml/build
cd langtons_ant_sfml/build
cmake ..
make install # As root
```
