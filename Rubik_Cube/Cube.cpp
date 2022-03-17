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
			std::cout << cube.cube[Top][i][k];
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[Left][i][j];
		}

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[Forward][i][j];
		}

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[Right][i][j];
		}

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[Back][i][j];
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << " ";
		}
		for (int k = 0; k < 3; k++)
		{
			std::cout << cube.cube[Botton][i][k];
		}
		std::cout << std::endl;
	}
	return out;
}

Cube::Cube()
{
	for (int color = 0; color < 6; color++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				this->cube[color][i][j] = colors[color];
			}
		}
	}
}

bool Cube::checkState()
{
	return false;
}
