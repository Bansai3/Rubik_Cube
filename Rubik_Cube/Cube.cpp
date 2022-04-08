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
			std::cout << cube.colors[cube.cube[Top][i][k]];
		}
		std::cout << std::endl;
	}
	 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.colors[cube.cube[Left][i][j]];
		}

		std::cout << " ";

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.colors[cube.cube[Forward][i][j]];
		}

		std::cout << " ";

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.colors[cube.cube[Right][i][j]];
		}

		std::cout << " ";

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.colors[cube.cube[Back][i][j]];
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << " ";
		}

		std::cout << " ";

		for (int k = 0; k < 3; k++)
		{
			std::cout << cube.colors[cube.cube[Bottom][i][k]];
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
			cube[Forward][i][j] = colour;
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
			cube[Botton][i][k] = colour;
		}
	}
}



void Cube::turn_matrix(int facet, bool cw)
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

	if (facet == Forward)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Top][2][j];
			side_col_matrix[j][1] = cube[Right][j][0];
			side_col_matrix[j][2] = cube[Botton][0][j];
			side_col_matrix[j][3] = cube[Left][j][2];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Right][i][0] = side_col_matrix[i][0];
				cube[Botton][0][i] = side_col_matrix[2 - i][1];
				cube[Left][i][2] = side_col_matrix[i][2];
				cube[Top][2][i] = side_col_matrix[2 - i][3];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Right][i][0] = side_col_matrix[2 - i][2];
				cube[Botton][0][i] = side_col_matrix[i][3];
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
			side_col_matrix[j][2] = cube[Botton][2][j];
			side_col_matrix[j][3] = cube[Left][j][0];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Right][i][2] = side_col_matrix[2 - i][2];
				cube[Botton][2][i] = side_col_matrix[i][3];
				cube[Left][i][0] = side_col_matrix[2 - i][0];
				cube[Top][0][i] = side_col_matrix[i][1];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Right][i][2] = side_col_matrix[i][0];
				cube[Botton][2][i] = side_col_matrix[2 - i][1];
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
			side_col_matrix[j][1] = cube[Forward][j][2];
			side_col_matrix[j][2] = cube[Botton][j][2];
			side_col_matrix[j][3] = cube[Back][j][0];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Top][i][2] = side_col_matrix[i][1];
				cube[Forward][i][2] = side_col_matrix[i][2];
				cube[Botton][i][2] = side_col_matrix[2 - i][3];
				cube[Back][i][0] = side_col_matrix[2 - i][0];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Top][i][2] = side_col_matrix[2 - i][3];
				cube[Forward][i][2] = side_col_matrix[i][0];
				cube[Botton][i][2] = side_col_matrix[i][1];
				cube[Back][i][0] = side_col_matrix[2 - i][2];
			}
		}
	}
	else if (facet == Left)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Top][j][0];
			side_col_matrix[j][1] = cube[Forward][j][0];
			side_col_matrix[j][2] = cube[Botton][j][0];
			side_col_matrix[j][3] = cube[Back][j][2];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Top][i][0] = side_col_matrix[2 - i][3];
				cube[Forward][i][0] = side_col_matrix[i][0];
				cube[Botton][i][0] = side_col_matrix[i][1];
				cube[Back][i][2] = side_col_matrix[2 - i][2];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Top][i][0] = side_col_matrix[i][1];
				cube[Forward][i][0] = side_col_matrix[2 - i][2];
				cube[Botton][i][0] = side_col_matrix[2 - i][3];
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
			side_col_matrix[j][2] = cube[Forward][0][j];
			side_col_matrix[j][3] = cube[Left][0][j];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Back][0][i] = side_col_matrix[i][3];
				cube[Right][0][i] = side_col_matrix[i][0];
				cube[Forward][0][i] = side_col_matrix[i][1];
				cube[Left][0][i] = side_col_matrix[i][2];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Back][0][i] = side_col_matrix[i][1];
				cube[Right][0][i] = side_col_matrix[i][2];
				cube[Forward][0][i] = side_col_matrix[i][3];
				cube[Left][0][i] = side_col_matrix[i][0];
			}
		}
	}
	else if (facet == Botton)
	{
		for (int j = 0; j < 3; j++)
		{
			side_col_matrix[j][0] = cube[Back][2][j];
			side_col_matrix[j][1] = cube[Right][2][j];
			side_col_matrix[j][2] = cube[Forward][2][j];
			side_col_matrix[j][3] = cube[Left][2][j];
		}
		if (cw)
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Back][2][i] = side_col_matrix[i][1];
				cube[Right][2][i] = side_col_matrix[i][2];
				cube[Forward][2][i] = side_col_matrix[i][3];
				cube[Left][2][i] = side_col_matrix[i][0];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				cube[Back][2][i] = side_col_matrix[i][3];
				cube[Right][2][i] = side_col_matrix[i][0];
				cube[Forward][2][i] = side_col_matrix[i][1];
				cube[Left][2][i] = side_col_matrix[i][2];
			}
		}
	}
}

void Cube::F(bool cw)
{
	turn_matrix(Forward, cw);
}

void Cube::B(bool cw)
{
	turn_matrix(Back, cw);
}

void Cube::L(bool cw)
{
	turn_matrix(Left, cw);
}

void Cube::R(bool cw)
{
	turn_matrix(Right, cw);
}

void Cube::U(bool cw)
{
	turn_matrix(Top, cw);
}

void Cube::D(bool cw)
{
	turn_matrix(Botton, cw);
}

void Cube::Mixing()
{
	srand(time(0));
	for (int i = 0; i < 15; i++)
	{
		int rand_number = rand() % 6;
		if (rand_number == 0)
		{
			F();
			std::cout << "F";
		}
		if (rand_number == 1)
		{
			B();
			std::cout << "B";
		}
		if (rand_number == 2)
		{
			L();
			std::cout << "L";
		}
		if (rand_number == 3)
		{
			R();
			std::cout << "R";
		}
		if (rand_number == 4)
		{
			U();
			std::cout << "U";
		}
		if (rand_number == 5)
		{
			D();
			std::cout << "D";
		}
	}
	std::cout << std::endl;
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
				this->cube[color][i][j] = (Color)(color % 2 == 0 ? odd : even);
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
	for (int i = 0; i < 5; i += 2)
	{
		if (abs(this->cube[i + 1][1][1] - this->cube[i][1][1]) != 3)
			return false;
	}
	if (this->cube[Forward][0][1], this->cube[Top][2][1])
		if (this->cube[Forward][1][0], this->cube[Left][2][1])
			if (this->cube[Forward][2][1], this->cube[Bottom][0][1])
				if (this->cube[Forward][1][2], this->cube[Right][1][0])

					if (this->cube[Top][0][1], this->cube[Back][0][1])
						if (this->cube[Top][1][0], this->cube[Left][0][1])
							if (this->cube[Top][1][2], this->cube[Right][0][1])

								if (this->cube[Left][0][1], this->cube[Back][1][2])
									if (this->cube[Left][2][1], this->cube[Bottom][1][0])


										if (this->cube[Right][1][2], this->cube[Back][1][0])
											if (this->cube[Right][2][1], this->cube[Bottom][1][2])

												if (this->cube[Bottom][2][1], this->cube[Back][2][1])




													return true;
}
