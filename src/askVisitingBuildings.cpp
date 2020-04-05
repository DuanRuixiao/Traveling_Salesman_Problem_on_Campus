// Implementation of asking for visiting buildings
#include "functions.h"

void askVisitingBuildings(vector<string>& buildings, unordered_map<string, unordered_map<string, double>>& graph) {
	cout << "Input the number of buildings you will visit today: ";
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cout << "Input the building name: ";
		string building;
		cin >> building;

		while (!graph.count(building)) {
			cerr << "Invalid building! Please try again: ";
			cin >> building;
		}

		buildings.push_back(building);
	}

	cout << endl;
}