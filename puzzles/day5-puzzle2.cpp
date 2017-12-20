#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream inputFile;
	//inputFile.open("../input/day5_puzzle2_example_input.txt");
	inputFile.open("../input/day5_puzzle2_input.txt");
	string line;

	if (!inputFile.is_open()) {
		cout << "Unable to open file" << endl;
		return -1;
	}

	vector<int> il;
	il.clear();

	while ( getline (inputFile,line) ) {
		int number = atoi(line.c_str());
		il.push_back(number);
	}
	inputFile.close();

	/*for (int i = 0; i < il.size(); i++) {
		cout << il.at(i) << endl;
	}
	cout << il.size() << endl;*/

	int index = 0;
	int newIndex;
	int steps = 0;

	while (index < il.size()) {
		newIndex = index + il.at(index);
		if (il.at(index) >= 3) {
			il.at(index)--;
		} else {
			il.at(index)++;
		}
		index = newIndex;
		steps++;
	}
	cout << steps << endl;
	return 0;
}
