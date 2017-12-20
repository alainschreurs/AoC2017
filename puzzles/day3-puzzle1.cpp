#include <string>
#include <cstdlib>
#include <iostream>


using namespace std;

int main(int argc, char* argv[]) {
	int input = atoi(argv[1]);
	int round = 1;
	int size = 1;
	int value = 1;

	while (input > value) {
		value += round * 8;
		round++;
		size += 2;
	}



	int row, column;

	if (input >= value - (size - 1)) {
		// bottom row
		cout << "Bottom row" << endl;
		row = size - 1;
		column = size - (value - input) - 1;
	} else if (input >= value - (size - 1) * 2) {
		// left column
		cout << "Left column" << endl;
		row = (value - (size - 1) * 2 - input) * -1;
		column = 0;
	} else if (input >= value - (size - 1) * 3) {
		// Top row
		cout << "Top row" << endl;
		row = 0;
		column = value - (size - 1) * 2 - input;
	} else  {
		// Right column
		cout << "Right column" << endl;
		row = value - (size - 1) * 3 - input;
		column = size - 1;
	}

	cout << "input: " << input << " size: " << size << " value: " << value << " : " << row << " - " << column << endl;

	row = row - size / 2;
	column = column - size / 2;

	cout << abs(row) + abs(column) << endl;

	return 0;
}
