#include <string>
#include <cstdlib>
#include <iostream>


using namespace std;



int main(int argc, char* argv[]) {
	int input = atoi(argv[1]);

	int fieldSize = 25;

	int field[fieldSize*fieldSize];
	int index = fieldSize / 2 + fieldSize / 2 * fieldSize;

	for (int i = 0; i < fieldSize; i++) {
		for (int j = 0; j < fieldSize; j++) {
			field[i + j * fieldSize] = 0;
		}
	}


	field[index] = 1;
	int heading = 1;
	index += heading;

	int newValue = 0;

	while (newValue <= input) {
		newValue = field[index + 1] + field[index - (fieldSize - 1)] + field[index - fieldSize] + field[index - (fieldSize + 1)] +
				   field[index - 1] + field[index + (fieldSize - 1)] + field[index + fieldSize] + field[index + (fieldSize + 1)];
		field[index] = newValue;
		if (heading == 1) {
			if (field[index - fieldSize] == 0) {
				heading = -fieldSize;
			}
		} else if (heading == -fieldSize) {
			if (field[index - 1] == 0) {
				heading = -1;
			}
		} else if (heading == -1) {
			if (field[index + fieldSize] == 0) {
				heading = fieldSize;
			}
		} else if (heading == fieldSize) {
			if (field[index + 1] == 0) {
				heading = 1;
			}
		}
		index += heading;
	}

	cout << newValue << endl;

	return 0;
}
