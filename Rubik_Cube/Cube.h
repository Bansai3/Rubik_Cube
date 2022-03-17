#pragma once
#include<iostream>

enum Facet
{
	top,
	botton,
	forward,
	back,
	left,
	right

};

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
	void establish_cube_state()
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					cube[i][j][k] = 'R';
				}
			}
		}
	}
};

