// Implementation of struct display.
// Include methods.

#include "Display.h"

void Display::vectInt1D(vector<int> nums) {
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

void Display::vectInt2D(vector<vector<int>> nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums[0].size(); j++) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Display::vectStr1D(vector<string> vect) {
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << " ";
	}
	cout << endl;
}

void Display::mapIntInt(map<int, int> m) {
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " -> " << it->second;
		cout << endl;
	}
	cout << endl;
}

void Display::unMapIntInt(unordered_map<int, int> m) {
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " -> " << it->second;
		cout << endl;
	}
	cout << endl;
}

void Display::setInt(set<int> s) {
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout <<  endl;
}

void Display::unSetInt(unordered_set<int> s) {
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void Display::unmapStrUnmapStrDoub(const unordered_map<string, unordered_map<string, double>>& m) {
	for (auto it1 = m.begin(); it1 != m.end(); it1++) {
		for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
			cout << it1->first << "->" << it2->first << ": " << it2->second << endl;
		}
	}
	cout << endl;
}

void Display::unmapStrUnmapStrVec1DStr(const unordered_map<string, unordered_map<string, vector<string>>>& m) {
	for (auto it1 = m.begin(); it1 != m.end(); it1++) {
		for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
			cout << it1->first << "->" << it2->first << ": ";
			for (string v : it2->second) {
				cout << v << " ";
			}
			cout << endl;
		}
	}
	cout << endl;
}
