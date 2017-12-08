#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream inputFile;
	//inputFile.open("../input/day2_puzzle1_example_input.txt");
	inputFile.open("../input/day2_puzzle1_input.txt");
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

		int biggest = 0;
		int smallest = 0;
		int number = 0;

		bool firstElement = true;

		while (ss >> buf) {
			//cout << "\"" << buf << "\"" << endl;

			number = atoi(buf.c_str());

			if (firstElement) {
				biggest = number;
				smallest = number;
				firstElement = false;
			} else {
				if (number > biggest) biggest = number;
				if (number < smallest) smallest = number;
			}
		}
		//cout << "Diff: " << (biggest - smallest) << endl;
		checksum += (biggest - smallest);
	}
	inputFile.close();
	cout << "Checksum: " << checksum << endl;
	return 0;
}
