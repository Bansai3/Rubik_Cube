#include "Cube.h"
#include <iostream>
#include <set>
#include <algorithm>


int main()
{
	srand(time(0));
	std::string filename = "cube_state.in";
	Cube cube;
	cube.LoadFromFile(filename);
	
	cube.Mixing();
	std::cout << cube << std::endl;
	cube.cubeSolve();
	std::cout << cube;

	return 0;
}