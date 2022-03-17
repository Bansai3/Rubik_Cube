#include "Cube.h"

std::ostream& operator<<(std::ostream& out, Cube& cube)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << " ";
		}
		for (int k = 0; k < 3; k++)
		{
			std::cout << cube.cube[top][i][k];
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[left][i][j];
		}

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[forward][i][j];
		}

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[right][i][j];
		}

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[back][i][j];
		}

		std::cout <<std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << " ";
		}
		for (int k = 0; k < 3; k++)
		{
			std::cout << cube.cube[botton][i][k];
		}
		std::cout << std::endl;
	}
	return out;
}
