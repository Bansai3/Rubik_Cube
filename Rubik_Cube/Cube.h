#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set>

enum Facet
{
	Top = 0,
	Bottom = 1,
	Forward = 2,
	Back = 3,
	Left = 4,
	Right = 5
};

enum Color
{
	R = 0,
	B,
	Y,
	O,
	G,
	W
};

class Cube
{
	char colors[6] = { 'R', 'B', 'Y', 'O', 'G', 'W' };
	std::map<std::set<char>, int> centerCubes = { {{'R','O'}, 0}, {{'B','G'}, 0}, {{'Y','W'}, 0} };

	std::map<std::set<char>, int> middleCubes = { {{'R','B'}, 0}, {{'B','Y'}, 0}, {{'Y','O'}, 0},
												  {{'O','G'}, 0}, {{'G','W'}, 0}, {{'W','R'}, 0},
												  {{'R','Y'}, 0}, {{'B','O'}, 0}, {{'Y','G'}, 0},
												  {{'O','W'}, 0}, {{'G','R'}, 0}, {{'B','W'}, 0}
	};

	std::map<std::string, int> cornerCubes = { {{'W','G','O'}, 0}, {{'G','O','Y'}, 0},
											   {{'O','Y','B'}, 0}, {{'Y','B','R'}, 0},
											   {{'B','R','W'}, 0}, {{'R','W','G'}, 0},
											   {{'W','O','B'}, 0}, {{'G','Y','R'}, 0}
	};

	Color cube[6][3][3];
	void turnMatrix(int matrixIndex, bool isClockwise = true);
public:
	Cube();
	bool checkState();
	friend std::ostream& operator<<(std::ostream& out, Cube& cube);
};

