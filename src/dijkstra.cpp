// Implementation of Dijkstra's algorithm to find shortest path.
#include "functions.h"

// Function to initialize dists and preds.
void initialization(unordered_map<string, double>& dists, unordered_map<string, string>& preds, 
	unordered_map<string, unordered_map<string, double>>& graph, string& source) {
	// Initialize distance from source to each vertex to 0 and predecessor to NIL.
	for (auto it = graph.begin(); it != graph.end(); it++) {
		dists[it->first] =__DBL_MAX__;
		preds[it->first] = "NIL";
	}

	dists[source] = 0.0;
}

// Function to relax vertices.
void relax(string& vrtx1, string& vrtx2, unordered_map<string, unordered_map<string, double>>& graph,
	unordered_map<string, double>& dists, unordered_map<string, string>& preds) {
	if (dists[vrtx1] > dists[vrtx2] + graph[vrtx2][vrtx1]) {
		dists[vrtx1] = dists[vrtx2] + graph[vrtx2][vrtx1];
		preds[vrtx1] = vrtx2;
	}
}

// Function to find minimum distance vertex not finished.
string findMinDistVertex(unordered_map<string, double>& dists, unordered_set<string>& finished) {
	double min_dist = __DBL_MAX__;
	string min_vrtx;

	for (auto it = dists.begin(); it != dists.end(); it++) {
		if (!finished.count(it->first)) {
			if (it->second < min_dist) {
				min_dist = it->second;
				min_vrtx = it->first;
			}
		}
	}

	return min_vrtx;
}

void dijkstra(unordered_map<string, unordered_map<string, double>>& graph, string& source, vector<string>& destinations, 
	unordered_map<string, unordered_map<string, double>>& dists, unordered_map<string, unordered_map<string, vector<string>>>& paths) {
	// Initialization.
	unordered_map<string, double> dist;
	unordered_map<string, string> preds;

	initialization(dist, preds, graph, source);

	// Construct a unordered_set to save used vertices.
	unordered_set<string> finished;

	while (finished.size() != graph.size()) {
		string min_vrtx = findMinDistVertex(dist, finished);
		finished.insert(min_vrtx);

		// Relax all neighbors of min_vrtx.
		for (auto it = graph[min_vrtx].begin(); it != graph[min_vrtx].end(); it++) {
			string neighbor = it->first;
			if (!finished.count(neighbor)) {
				relax(neighbor, min_vrtx, graph, dist, preds);
			}
		}
	}

	// Save shortest path.
	for (string destination : destinations) {
		if (destination == source) { continue; }
		vector<string> path;
		string vrtx = destination;
		while (preds[vrtx] != "NIL") {
			path.push_back(vrtx);
			vrtx = preds[vrtx];
		}
		path.push_back(source);

		reverse(path.begin(), path.end());

		paths[source][destination] = path;

		// Calculate shortest distance.
		double dis = 0;
		for (int i = 1; i < path.size(); i++) {
			dis += graph[path[i - 1]][path[i]];
		}
		dists[source][destination] = dis;
	}
	
}