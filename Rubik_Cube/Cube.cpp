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

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.colors[cube.cube[Forward][i][j]];
		}

		for (int j = 0; j < 3; j++)
		{
			std::cout << cube.colors[cube.cube[Right][i][j]];
		}

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
		for (int k = 0; k < 3; k++)
		{
			std::cout << cube.colors[cube.cube[Bottom][i][k]];
		}
		std::cout << std::endl;
	}
	return out;
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
