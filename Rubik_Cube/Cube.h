#pragma once
#include <iostream>

enum Facet
{
	Top = 0,
	Botton,
	Forward,
	Back,
	Left,
	Right
};

enum Color
{
	R = 0,
	O,
	Y,
	G,
	B,
	W
};

class Cube
{
	char colors[6] = { 'R', 'O', 'Y', 'G', 'B', 'W' };
	char cube[6][3][3];

public:
	Cube();
	bool checkState();
	friend std::ostream& operator<<(std::ostream& out, Cube& cube);
};

