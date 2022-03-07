#include <iostream>
#include "ofMain.h"

#pragma once

struct Cell {

public:
	bool isAlive;
	float distance;
	ofColor color;
};


class Grid {

public:
	glm::vec2 center = glm::vec2(50, 50);
	std::array<std::array<Cell, 100>, 100> arr;

	bool isOneColor;
	float probability = 0.5;

	void setup();
	int getNeighbours(int x, int y);
	void nextStep(const ofColor& color);
	void draw();
};