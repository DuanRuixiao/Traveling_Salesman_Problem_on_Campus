#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "include.h"

void readTextFile(unordered_map<string, unordered_map<string, double> >&);

void dijkstra(unordered_map<string, unordered_map<string, double> >&, string&, vector<string>&, 
	unordered_map<string, unordered_map<string, double> >&, unordered_map<string, unordered_map<string, vector<string> > >&);

void askVisitingBuildings(vector<string>&, unordered_map<string, unordered_map<string, double> >&);

void tspByNaive(unordered_map<string, unordered_map<string, double> >&, 
	unordered_map<string, unordered_map<string, vector<string> > >&, vector<string>&);

void tspByBB(unordered_map<string, unordered_map<string, double> >&,
	unordered_map<string, unordered_map<string, vector<string> > >&, vector<string>&);

#endif // !FUNCTIONS_H#pragma once
