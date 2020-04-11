// Structure specification of display.

#ifndef DISPLAY_H
#define DISPLAY_H

#include "include.h"

class Display {
public:
	// There is no attribute in this struct.

	// Define methods.

	// 1D int vector.
	void vectInt1D(vector<int>);

	// 2D int vector.
	void vectInt2D(vector< vector<int> >);

	// 1D string vector.
	void vectStr1D(vector<string>);

	// <int, int> map.
	void mapIntInt(map<int, int>);

	// <int, int> unordered_map.
	void unMapIntInt(unordered_map<int, int>);

	// <int> set.
	void setInt(set<int>);

	// <int> unordered_set.
	void unSetInt(unordered_set<int>);

	// <string, string, int>.
	void unmapStrUnmapStrDoub(const unordered_map< string, unordered_map<string, double> >&);

	// <string, string, vector<string>>.
	void unmapStrUnmapStrVec1DStr(const unordered_map< string, unordered_map< string, vector<string> > >&);
};

#endif // !DISPLAY_H