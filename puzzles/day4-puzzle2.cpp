#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream inputFile;
	//inputFile.open("../input/day4_puzzle2_example_input.txt");
	inputFile.open("../input/day4_puzzle2_input.txt");
	string line;

	if (!inputFile.is_open()) {
		cout << "Unable to open file" << endl;
		return -1;
	}

	int numValid = 0;

	while ( getline (inputFile,line) ) {
		string str(line);
		string buf;
		stringstream ss(str);

		vector<string> phrases;
		phrases.clear();

		while (ss >> buf) {
			phrases.push_back(buf);
		}

		bool valid = true;

		for (int i = 0; i < phrases.size() - 1; i++) {
			for (int j = i + 1; j < phrases.size(); j++) {
				//cout << phrases.at(i) << " == " << phrases.at(j) << endl;
				sort(phrases.at(i).begin(), phrases.at(i).end());
				sort(phrases.at(j).begin(), phrases.at(j).end());
				//cout << phrases.at(i) << " == " << phrases.at(j) << endl;
				if (phrases.at(i) == phrases.at(j)) {
					valid = false;
				}
			}
		}
		if (valid) {
			numValid++;
		}
	}
	inputFile.close();
	cout << "Valid passphrases: " << numValid << endl;
	return 0;
}
