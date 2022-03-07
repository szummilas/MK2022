#include <iostream>
#include "ofMain.h"

#pragma once

struct Cell {

public:
	bool isAlive;
};


class Grid {

public:
	std::array<std::array<Cell, 100>, 100> arr;

	void setup();
	int getNeighbours(int x, int y);
	void nextStep();
	void draw();
};