// Traveling_Salesman_Problem_on_Campus.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This code implements two algorithm solving TSP in Northeastern University campus: naive and branch and bound.

// There are 3 steps to finish this project:
// 1. Construct graph given a text file containing information of edges.
// 2. Apply Dijkstra's algorithm to find shorest path and distance between any two vertices.
// 3. Given multiple vertices, find order of the vertices, making the total distance is smallest.4

// #include "include.h"
#include "Display.h"
#include "functions.h"

Display disp;

int main()
{
    // Read textfile from ../inputs.
	unordered_map<string, unordered_map<string, double>> graph;
	readTextFile(graph);
//	 disp.unmapStrUnmapStrDoub(graph);
	// ----------------------------- //

	// Ask for visiting vertices.
	vector<string> buildings;
	askVisitingBuildings(buildings, graph);
	// ----------------------------- //

	// Apply Dijkstra's algorithm to find shortest path and distance for all visiting buildings.
	unordered_map<string, unordered_map<string, double>> dists;
	unordered_map<string, unordered_map<string, vector<string>>> paths;
	for (string source : buildings) {
		dijkstra(graph, source, buildings, dists, paths);
	}
//	disp.unmapStrUnmapStrDoub(dists);
//	disp.unmapStrUnmapStrVec1DStr(paths);
	// ----------------------------- //

	// Naive method.
	// Find all permutations and display the minimum distance path.
	tspByNaive(dists, paths, buildings);
	// ----------------------------- //

	// Branch and Bound method.
	// Initial upper bound: greedy algorithm.
	// DFS + MST to find lower bound for each branch.
	// If lower bound is larger than upper bound, cut this branch.
	tspByBB(dists, paths, buildings);
	// ----------------------------- //

	return 0;
}