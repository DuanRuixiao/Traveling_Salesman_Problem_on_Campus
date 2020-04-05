// Implementation of reading textfile.
#include "functions.h"

void readTextFile(unordered_map<string, unordered_map<string, double>>& graph) {
	// get the filename which saved graph
	string filename = "../../inputs/edge.txt";

	// read info from text file
	ifstream file(filename, ios::in);

	string vrtx1, vrtx2;
	double edge;

	if (!file) {   // target file not exist, return error
		cerr << "Cant open! Invalid filename." << endl;
	}
	else {
		while (file >> vrtx1 >> vrtx2 >> edge) {
			graph[vrtx1][vrtx2] = edge;
			graph[vrtx2][vrtx1] = edge;
		}
		file.close();   // close target file
	}
}