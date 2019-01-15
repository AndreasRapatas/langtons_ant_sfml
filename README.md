# Langton's Ant
[Langton's Ant](https://en.wikipedia.org/wiki/Langton%27s_ant) is a [cellular automaton](https://en.wikipedia.org/wiki/Cellular_automaton) with a complex emergent behavior but very simple set of rules:
* At a white square, turn 90° right, flip the color of the square, move forward one unit
* At a black square, turn 90° left, flip the color of the square, move forward one unit

![Preview](https://i.imgur.com/3lk8FZU.png "Langtons Ant")

This project implements Langton's Ant using C++ and displays it using [Rapatas/CAVIS](https://github.com/Rapatas/CAVIS)

# Requirements
* [Rapatas/flat_matrix](https://github.com/Rapatas/flat_matrix)
* [Rapatas/CAVIS](https://github.com/Rapatas/CAVIS)
* [SFML](https://www.sfml-dev.org/index.php)
