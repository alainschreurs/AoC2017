#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream inputFile;
	//inputFile.open("../input/day2_puzzle2_example_input.txt");
	inputFile.open("../input/day2_puzzle2_input.txt");
	string line;

	if (!inputFile.is_open()) {
		cout << "Unable to open file" << endl;
		return -1;
	}

	int checksum = 0;

	while ( getline (inputFile,line) ) {
		cout << line << '\n';
		string str(line);
		string buf; // Have a buffer string
		stringstream ss(str); // Insert the string into a stream

		int number = 0;
		vector<int> values;
		while (ss >> buf) {
			number = atoi(buf.c_str());
			values.push_back(number);
		}

		for (int i = 0; i < values.size(); i++) {
			for (int j = 0; j < values.size(); j++) {
				if (i != j && values.at(i) % values.at(j) == 0) {
					checksum += values.at(i) / values.at(j);
				}
			}
		}
	}
	inputFile.close();
	cout << "Checksum: " << checksum << endl;
	return 0;
}
