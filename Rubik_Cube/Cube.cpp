#include "Cube.h"

std::ostream& operator<<(std::ostream& out, Cube& cube)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << " ";
		}

		std::cout << " ";

		for (int k = 0; k < 3; k++)
		{
			std::cout << cube.cube[Top][i][k];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[Left][i][j];
		}

		std::cout << " ";

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[Forward][i][j];
		}

		std::cout << " ";

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[Right][i][j];
		}

		std::cout << " ";

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[Back][i][j];
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << " ";
		}

		std::cout << " ";

		for (int k = 0; k < 3; k++)
		{
			std::cout << cube.cube[Botton][i][k];
		}
		std::cout << std::endl;
	}
	return out;
}

void Cube::load_from_file(std::string filename)
{
	char colour;

	std::ifstream fin(filename);

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			fin >> colour;
			cube[top][i][k] = colour;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fin >> colour;
			cube[left][i][j] = colour;
		}

		for (int j = 0; j < 3; j++)
		{
			fin >> colour;
			cube[forward][i][j] = colour;
		}

		for (int j = 0; j < 3; j++)
		{
			fin >> colour;
			cube[right][i][j] = colour;
		}

		for (int j = 0; j < 3; j++)
		{
			fin >> colour;
			cube[back][i][j] = colour;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			fin >> colour;
			cube[botton][i][k] = colour;
		}
	}
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
