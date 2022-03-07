#include "game.h"

void Grid::setup() {
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			arr[x][y].isAlive = ofRandomf() > 0.5 ? 1 : 0;
		}
	}
}

int Grid::getNeighbours(int x, int y) {

	/*
		[ ] [ ] [ ]
		[ ] [ ] [ ]
		[ ] [ ] [ ]
	*/

	int sum = 0;
	sum += (arr[x - 1][y].isAlive == 1);
	sum += (arr[x + 1][y].isAlive == 1);
	sum += (arr[x][y + 1].isAlive == 1);
	sum += (arr[x][y - 1].isAlive == 1);
	sum += (arr[x - 1][y - 1].isAlive == 1);
	sum += (arr[x - 1][y + 1].isAlive == 1);
	sum += (arr[x + 1][y - 1].isAlive == 1);
	sum += (arr[x + 1][y + 1].isAlive == 1);

	return sum;

}

void Grid::nextStep() {

	std::array<std::array<int, 100>, 100> arr_alive;

	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			arr_alive[x][y] = getNeighbours(x, y);
		}
	}

	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {

			if (arr[x][y].isAlive == 1) {
				if (arr_alive[x][y] > 3) {
					arr[x][y].isAlive = 0;
				}

				if (arr_alive[x][y] < 2) {
					arr[x][y].isAlive = 0;
				}
			}

			else {
				if (arr_alive[x][y] == 3) {
					arr[x][y].isAlive = 1;
				}
			}
		}
	}
}

void Grid::draw() {
	
	for (int x = 0; x < 100; x++) {
		for (int y = 0; y < 100; y++) {
			ofSetColor(ofColor::ghostWhite);
			ofFill();
			
			if (arr[x][y].isAlive) {
				ofDrawRectangle(x * 10, y * 10, 10, 10);
			}
		}
	}
}
