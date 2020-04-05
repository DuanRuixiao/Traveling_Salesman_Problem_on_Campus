// Implementation of naive method for TSP.
#include "functions.h"

// Find all permutations of given buildings.
// Calculate all distances and return the minimum one with its path.

// DFS function to find all permutations.
void dfs(vector<vector<string>>& pers, vector<string>& per, vector<string>& buildings, unordered_map<string, bool>& used) {
	if (per.size() == buildings.size()) {
		per.push_back(per[0]);
		pers.push_back(per);
		per.pop_back();
		return;
	}

	for (string building : buildings) {
		if (!used[building]) {
			per.push_back(building);
			used[building] = true;
			dfs(pers, per, buildings, used);
			per.pop_back();
			used[building] = false;
		}
	}
}

// Calculate distance of path.
double calculateDist(vector<string>& path, unordered_map<string, unordered_map<string, double>>& dists) {
	double dist = 0.0;

	for (int i = 1; i < path.size(); i++) {
		dist += dists[path[i - 1]][path[i]];
	}

	return dist;
}

void tspByNaive(unordered_map<string, unordered_map<string, double>>& dists,
	unordered_map<string, unordered_map<string, vector<string>>>& paths, vector<string>& buildings) {
	// DFS to find permutations.
	vector<vector<string>> pers;
	vector<string> per;
	
	// Define used array.
	unordered_map<string, bool> used;
	for (string building : buildings) {
		used[building] = false;
	}

	// DFS.
	dfs(pers, per, buildings, used);

	// Calculate all distances and maintain minimum one.
	double min_dist = __DBL_MAX__;
	vector<string> min_path;
	for (vector<string> path : pers) {
		double dist = calculateDist(path, dists);
		if (dist < min_dist) {
			min_dist = dist;
			min_path = path;
		}
	}

	//// Display general path of min_path.
	//cout << "The general minimum path is ";
	//for (string v : min_path) {
	//	cout << v << " ";
	//}
	//cout << "." << endl << "And the total minimum distance is " << min_dist << " miles." << endl;

	// Display detail path of min_path.
	cout << "The entire minimum path by naive method is ";
	for (int i = 1; i < min_path.size(); i++) {
		vector<string> seg_path = paths[min_path[i - 1]][min_path[i]];
		for (int j = 0; j < seg_path.size()-1; j++) {
			cout << seg_path[j] << " -> ";
		}
	}
	cout << min_path.back() << "," << endl;
	cout << "and the total minimum distance is " << min_dist << " miles." << endl;
}