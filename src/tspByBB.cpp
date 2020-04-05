// Implementation of branch and bound method for TSP.
#include "functions.h"

// Define a class for priority_queue.
class Comparator {
public:
	bool operator() (tuple<string, string, double>& edge1, tuple<string, string, double>& edge2) {
		return get<2>(edge1) < get<2>(edge2);
	}
};

// Function to find upper bound by greedy algorithm.
double upperBoundByGreedy(vector<string>& buildings, unordered_map<string, unordered_map<string, double>>& dists) {
	double upper_bound = 0.0;

	// Define a set to save all used buildings.
	unordered_set<string> used;

	string start_building = buildings[0];
	while (1) {
		used.insert(start_building);
		string end_building;

		// Find the minimum edge and go through that direction.
		double min_dist = __DBL_MAX__;
		for (auto info : dists[start_building]) {
			if (!used.count(info.first) && info.second < min_dist) {
				min_dist = info.second;
				end_building = info.first;
			}
		}

		// If start_building is the last vertex, add the distance between it and first building to upper bound.
		if (end_building == "") {
			upper_bound += dists[start_building][buildings[0]];
			break;
		}
		// Else, update start_building and upper_bound.
		else {
			upper_bound += min_dist;
			start_building = end_building;
		}
	}

	return upper_bound;
}

// Functions to make union find.
string findSet(string& building, unordered_map<string, string>& labels) {
	string par = labels[building];

	while (labels[par] != par) {
		par = labels[par];
	}

	// Path compression.
	string node = building;
	while (node != par) {
		string tmp = labels[node];
		labels[node] = par;
		node = tmp;
	}

	return par;
}

void unionSet(string& building1, string& building2, unordered_map<string, string>& labels) {
	string par1 = findSet(building1, labels);
	string par2 = findSet(building2, labels);

	if (par1 != par2) {
		labels[par1] = par2;
	}
}

// Function to caculate MST of given vertices.
double calculateMST(unordered_map<string, bool>& remain_buildings, unordered_map<string, unordered_map<string, double>>& dists) {
	double mst_dist = 0.0;

	// Extract buildings need to be in MST.
	unordered_set<string> buildings;
	for (auto info : remain_buildings) {
		if (info.second) {
			buildings.insert(info.first);
		}
	}

	// Construct a priority_queue to save all edges.
	priority_queue<tuple<string, string, double>, vector<tuple<string, string, double>>, Comparator> pq;
	for (auto info : dists) {
		string u = info.first;
		for (auto info2 : info.second) {
			if (buildings.count(u) && buildings.count(info2.first)) {
				pq.push(make_tuple(u, info2.first, info2.second));
			}
		}
	}

	// Constrcut labels.
	unordered_map<string, string> labels;
	for (string building : buildings) {
		labels[building] = building;
	}

	// Constrcut MST.
	while (!pq.empty()) {
		tuple<string, string, double> edge = pq.top();
		pq.pop();

		if (findSet(get<0>(edge), labels) != findSet(get<1>(edge), labels)) {
			unionSet(get<0>(edge), get<1>(edge), labels);
			mst_dist += get<2>(edge);
		}
	}

	return mst_dist;
}

void tspByBB(unordered_map<string, unordered_map<string, double>>& dists,
	unordered_map<string, unordered_map<string, vector<string>>>& paths, vector<string>& buildings) {
	// Get initial upper bound by greedy algorithm.
	double upper_bound = upperBoundByGreedy(buildings, dists);

	// Get ready for DFS + cut.
	unordered_map<string, bool> remain_buildings;
	for (string building : buildings) {
		remain_buildings[building] = true;
	}

	//// Display general path of min_path.
	//cout << "The general minimum path is ";
	//for (string v : min_path) {
	//	cout << v << " ";
	//}
	//cout << "." << endl << "And the total minimum distance is " << min_dist << " miles." << endl;

	//// Display detail path of min_path.
	//cout << "The entire minimum path is ";
	//for (int i = 1; i < min_path.size(); i++) {
	//	vector<string> seg_path = paths[min_path[i - 1]][min_path[i]];
	//	for (int j = 0; j < seg_path.size() - 1; j++) {
	//		cout << seg_path[j] << " ";
	//	}
	//}
	//cout << min_path.back() << "." << endl;
	//cout << "And the total minimum distance is " << min_dist << " miles." << endl;
}