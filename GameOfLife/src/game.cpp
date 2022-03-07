#include "game.h"

void Grid::setup() {
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			arr[x][y].isAlive = ofRandomf() > probability ? 1 : 0;
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

void Grid::nextStep(const ofColor& color) {

	std::array<std::array<int, 100>, 100> arr_alive;

	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			arr_alive[x][y] = getNeighbours(x, y);

			arr[x][y].distance = glm::distance(center, glm::vec2(x, y));

			if (!isOneColor) {
				arr[x][y].color = ofColor(ofRandomf() * 10 * arr[x][y].distance, ofRandomf() * 10 * arr[x][y].distance, ofRandomf() * 10 * arr[x][y].distance, 100);
			}
			else {
				arr[x][y].color = color + ofColor(0, 0, 0, 100);
			}
			
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
			ofSetColor(arr[x][y].color);
			ofFill();
			
			if (arr[x][y].isAlive) {
				ofDrawBox(x * 10 - 0.5, y * 10 - 0.5, 0, 9.5, 9.5, 9.5);
			}
		}
	}
}
