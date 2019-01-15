#include <CAVIS/window.h>

#include "langtons_ant.h"

int main() {

	// HD aspect ratio = 16:9
	unsigned height = 100;
	unsigned width = height * 16 / 9;
	unsigned pixel_size = 4;

	Window<LangtonsAnt> window(width, height, pixel_size, "Langton's Ant");
	window.run();

	return 0;
}
