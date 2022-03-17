#include "Cube.h"

std::ostream& operator<<(std::ostream& out, Cube& cube)
{
	for (int i = 0; i < 3; i++)
	{
		int count_of_level = 0;

		for (int j = 0; j < 3; j++)
		{
			std::cout << " ";
		}
		for (int k = 0; k < 3; k++)
		{
			std::cout << cube.cube[back][count_of_level][k];
		}
		for (int j = 0; j < 3; j++)
		{
			std::cout << " ";
		}
		count_of_level++;

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
	}

	



}
