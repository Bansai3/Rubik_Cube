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
			std::cout << cube.cube[top][i][k];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[left][i][j];
		}

		std::cout << " ";

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[forward][i][j];
		}

		std::cout << " ";

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[right][i][j];
		}

		std::cout << " ";

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.cube[back][i][j];
		}

		std::cout <<std::endl;
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
			std::cout << cube.cube[botton][i][k];
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
