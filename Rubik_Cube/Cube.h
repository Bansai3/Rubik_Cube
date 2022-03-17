#pragma once
#include<iostream>


enum 
{
	top,
	botton,
	forward,
	back,
	left,
	right

} Facet;

class Cube
{
	char cube[6][3][3];

	char top[3][3];
	char botton[3][3];
	char forward[3][3];
	char back[3][3];
	char left[3][3];
	char right[3][3];

public:
	friend std::ostream& operator<<(std::ostream& out, Cube& cube);
};

