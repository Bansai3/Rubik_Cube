#include "Cube.h"

std::ostream& operator<<(std::ostream& out, Cube& cube)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << " ";

		std::cout << " ";

		for (int k = 0; k < 3; k++)
			std::cout << cube.cube[Top][i][k];
		std::cout << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << cube.cube[Left][i][j];

		std::cout << " ";

		for (int j = 0; j < 3; j++)
			std::cout << cube.cube[Front][i][j];

		std::cout << " ";

		for (int j = 0; j < 3; j++)
			std::cout << cube.cube[Right][i][j];

		std::cout << " ";

		for (int j = 0; j < 3; j++)
			std::cout << cube.cube[Back][i][j];

		std::cout << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << " ";

		std::cout << " ";

		for (int k = 0; k < 3; k++)
			std::cout << cube.cube[Bottom][i][k];
		std::cout << std::endl;
	}
	return out;
}

void Cube::LoadFromFile(std::string filename)
{
	char colour;

	std::ifstream fin(filename);

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			fin >> colour;
			cube[Top][i][k] = colour;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fin >> colour;
			cube[Left][i][j] = colour;
		}

		for (int j = 0; j < 3; j++)
		{
			fin >> colour;
			cube[Front][i][j] = colour;
		}

		for (int j = 0; j < 3; j++)
		{
			fin >> colour;
			cube[Right][i][j] = colour;
		}

		for (int j = 0; j < 3; j++)
		{
			fin >> colour;
			cube[Back][i][j] = colour;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			fin >> colour;
			cube[Bottom][i][k] = colour;
		}
	}
}



void Cube::turnMatrix(int facet, bool cw)
{
	char facet_matrix[3][3];
	char side_col_matrix[3][4];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			facet_matrix[i][j] = cube[facet][i][j];
		}
	}

	if (cw)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cube[facet][j][2 - i] = facet_matrix[i][j];
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cube[facet][2 - j][i] = facet_matrix[i][j];
			}
		}
	}

	if (facet == Front)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Top][2][j];
			side_col_matrix[j][1] = cube[Right][j][0];
			side_col_matrix[j][2] = cube[Bottom][0][j];
			side_col_matrix[j][3] = cube[Left][j][2];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Right][i][0] = side_col_matrix[i][0];
				cube[Bottom][0][i] = side_col_matrix[2 - i][1];
				cube[Left][i][2] = side_col_matrix[i][2];
				cube[Top][2][i] = side_col_matrix[2 - i][3];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Right][i][0] = side_col_matrix[2 - i][2];
				cube[Bottom][0][i] = side_col_matrix[i][3];
				cube[Left][i][2] = side_col_matrix[2 - i][0];
				cube[Top][2][i] = side_col_matrix[i][1];
			}
		}
	}
	else if (facet == Back)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Top][0][j];
			side_col_matrix[j][1] = cube[Right][j][2];
			side_col_matrix[j][2] = cube[Bottom][2][j];
			side_col_matrix[j][3] = cube[Left][j][0];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Right][i][2] = side_col_matrix[2 - i][2];
				cube[Bottom][2][i] = side_col_matrix[i][3];
				cube[Left][i][0] = side_col_matrix[2 - i][0];
				cube[Top][0][i] = side_col_matrix[i][1];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Right][i][2] = side_col_matrix[i][0];
				cube[Bottom][2][i] = side_col_matrix[2 - i][1];
				cube[Left][i][0] = side_col_matrix[i][2];
				cube[Top][0][i] = side_col_matrix[2 - i][3];
			}
		}
	}
	else if (facet == Right)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Top][j][2];
			side_col_matrix[j][1] = cube[Front][j][2];
			side_col_matrix[j][2] = cube[Bottom][j][2];
			side_col_matrix[j][3] = cube[Back][j][0];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Top][i][2] = side_col_matrix[i][1];
				cube[Front][i][2] = side_col_matrix[i][2];
				cube[Bottom][i][2] = side_col_matrix[2 - i][3];
				cube[Back][i][0] = side_col_matrix[2 - i][0];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Top][i][2] = side_col_matrix[2 - i][3];
				cube[Front][i][2] = side_col_matrix[i][0];
				cube[Bottom][i][2] = side_col_matrix[i][1];
				cube[Back][i][0] = side_col_matrix[2 - i][2];
			}
		}
	}
	else if (facet == Left)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Top][j][0];
			side_col_matrix[j][1] = cube[Front][j][0];
			side_col_matrix[j][2] = cube[Bottom][j][0];
			side_col_matrix[j][3] = cube[Back][j][2];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Top][i][0] = side_col_matrix[2 - i][3];
				cube[Front][i][0] = side_col_matrix[i][0];
				cube[Bottom][i][0] = side_col_matrix[i][1];
				cube[Back][i][2] = side_col_matrix[2 - i][2];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Top][i][0] = side_col_matrix[i][1];
				cube[Front][i][0] = side_col_matrix[2 - i][2];
				cube[Bottom][i][0] = side_col_matrix[2 - i][3];
				cube[Back][i][2] = side_col_matrix[2 - i][0];
			}
		}
	}
	else if (facet == Top)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Back][0][j];
			side_col_matrix[j][1] = cube[Right][0][j];
			side_col_matrix[j][2] = cube[Front][0][j];
			side_col_matrix[j][3] = cube[Left][0][j];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Back][0][i] = side_col_matrix[i][3];
				cube[Right][0][i] = side_col_matrix[i][0];
				cube[Front][0][i] = side_col_matrix[i][1];
				cube[Left][0][i] = side_col_matrix[i][2];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Back][0][i] = side_col_matrix[i][1];
				cube[Right][0][i] = side_col_matrix[i][2];
				cube[Front][0][i] = side_col_matrix[i][3];
				cube[Left][0][i] = side_col_matrix[i][0];
			}
		}
	}
	else if (facet == Bottom)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Back][2][j];
			side_col_matrix[j][1] = cube[Right][2][j];
			side_col_matrix[j][2] = cube[Front][2][j];
			side_col_matrix[j][3] = cube[Left][2][j];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Back][2][i] = side_col_matrix[i][1];
				cube[Right][2][i] = side_col_matrix[i][2];
				cube[Front][2][i] = side_col_matrix[i][3];
				cube[Left][2][i] = side_col_matrix[i][0];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Back][2][i] = side_col_matrix[i][3];
				cube[Right][2][i] = side_col_matrix[i][0];
				cube[Front][2][i] = side_col_matrix[i][1];
				cube[Left][2][i] = side_col_matrix[i][2];
			}
		}
	}
}

void Cube::F(bool cw)
{
	turnMatrix(Front, cw);
}

void Cube::B(bool cw)
{
	turnMatrix(Back, cw);
}

void Cube::L(bool cw)
{
	turnMatrix(Left, cw);
}

void Cube::R(bool cw)
{
	turnMatrix(Right, cw);
}

void Cube::U(bool cw)
{
	turnMatrix(Top, cw);
}

void Cube::D(bool cw)
{
	turnMatrix(Bottom, cw);
}

void Cube::Mixing()
{
	for (int i = 0; i < 10; i++)
	{
		int randNumber = rand() % 6;
		if (randNumber == 0)
			F();
		if (randNumber == 1)
			B();
		if (randNumber == 2)
			L();
		if (randNumber == 3)
			R();
		if (randNumber == 4)
			U();
		if (randNumber == 5)
			D();
	}
}

long long Cube::getHash()
{
	unsigned long long hash = 0;
	unsigned long long num = 1;
	/*int primeNumbers[54] = {2,   3,   5,   7,   11,  13,  17,  19,  23,
							 29,  31,  37,  41,  43,  47,  53,  59,  61,
							 67,  71,  73,  79,  83,  89,  97,  101, 103,
							 107, 109, 113, 127, 131, 137, 139, 149, 151,
							 157, 163, 167, 173, 179, 181, 191, 193, 197,
							 199, 211, 223,	227, 229, 233, 239,	241, 251 };

	for (int color = 0; color < 6; color++)
	{
		hash *= primeNumbers[color];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int x = (int)(std::find(colors, colors + 6, this->cube[color][i][j]) - colors);
				hash += (num++) * (x + 1) * (i + 1) * (j + 1);
			}
		}
	}*/

	for (int color = 0; color < 6; color++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				int x = (int)(this->cube[color][i][j] - 'A' + 1);
				hash = (hash + num * x) % INT64_MAX;
				num = (num * 6) % INT64_MAX;
			}
		}
	}

	return hash;
}

Cube::Cube()
{

	int odd = 0;
	int even = 3;
	for (int color = 0; color < 6; color++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				this->cube[color][i][j] = colors[(color % 2 == 0 ? odd : even)];
			}
		}
		if (color % 2 == 0)
			odd++;
		else
			even++;
	}
}

bool Cube::checkState()
{
	centerCubes[{this->cube[Front][1][1], this->cube[Back][1][1]}]++;
	centerCubes[{this->cube[Top][1][1], this->cube[Bottom][1][1]}]++;
	centerCubes[{this->cube[Left][1][1], this->cube[Right][1][1]}]++;
	for (int i = 0; i < 5; i += 2)
	{
		if (abs(this->cube[i + 1][1][1] - this->cube[i][1][1]) != 3)
			return false;
	}
	if (this->cube[Forward][0][1], this->cube[Top][2][1]);
	if (this->cube[Forward][1][0], this->cube[Left][2][1]);
	if (this->cube[Forward][2][1], this->cube[Bottom][0][1]);
	if (this->cube[Forward][1][2], this->cube[Right][1][0]);

	if (this->cube[Top][0][1], this->cube[Back][0][1]);
	if (this->cube[Top][1][0], this->cube[Left][0][1]);
	if (this->cube[Top][1][2], this->cube[Right][0][1]);

	if (this->cube[Left][0][1], this->cube[Back][1][2]);
	if (this->cube[Left][2][1], this->cube[Bottom][1][0]);



	if (this->cube[Bottom][2][1], this->cube[Back][2][1]);
	middleCubes[{this->cube[Front][0][1], this->cube[Top][2][1]}]++;
	middleCubes[{this->cube[Front][1][0], this->cube[Left][1][2]}]++;
	middleCubes[{this->cube[Front][2][1], this->cube[Bottom][0][1]}]++;
	middleCubes[{this->cube[Front][1][2], this->cube[Right][1][0]}]++;
	middleCubes[{this->cube[Top][0][1], this->cube[Back][0][1]}]++;
	middleCubes[{this->cube[Top][1][0], this->cube[Left][0][1]}]++;
	middleCubes[{this->cube[Top][1][2], this->cube[Right][0][1]}]++;
	middleCubes[{this->cube[Left][1][0], this->cube[Back][1][2]}]++;
	middleCubes[{this->cube[Left][2][1], this->cube[Bottom][1][0]}]++;
	middleCubes[{this->cube[Right][1][2], this->cube[Back][1][0]}]++;
	middleCubes[{this->cube[Right][2][1], this->cube[Bottom][1][2]}]++;
	middleCubes[{this->cube[Bottom][2][1], this->cube[Back][2][1]}]++;


	cornerCubes[{this->cube[Top][2][0], this->cube[Front][0][0], this->cube[Left][0][2]}]++;
	cornerCubes[{this->cube[Top][2][2], this->cube[Front][0][2], this->cube[Right][0][0]}]++;
	cornerCubes[{this->cube[Top][0][0], this->cube[Left][0][0], this->cube[Back][2][0]}]++;
	cornerCubes[{this->cube[Top][0][2], this->cube[Right][0][2], this->cube[Back][0][0]}]++;
	cornerCubes[{this->cube[Front][2][0], this->cube[Left][2][2], this->cube[Bottom][0][0]}]++;
	cornerCubes[{this->cube[Front][2][2], this->cube[Right][2][0], this->cube[Bottom][0][2]}]++;
	cornerCubes[{this->cube[Left][2][0], this->cube[Back][2][2], this->cube[Bottom][2][0]}]++;
	cornerCubes[{this->cube[Right][2][2], this->cube[Back][0][2], this->cube[Bottom][2][2]}]++;

	for (auto c : centerCubes)
		if (c.second != 0)
			return false;
	for (auto c : middleCubes)
		if (c.second != 0)
			return false;
	for (auto c : cornerCubes)
		if (c.second != 0)
			return false;

	return true;
}
