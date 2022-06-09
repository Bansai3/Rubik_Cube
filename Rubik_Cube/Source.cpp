#include "Cube.h"

int main()
{
	srand(time(0));
	std::string filename = "cube_state.in";
	Cube cube;
	cube.LoadFromFile(filename);
	
	cube.Mixing();
	std::cout << cube << std::endl;
	//std::cout << cube.checkState();

	cube.cubeSolve();
	std::cout << cube << "\n";

	for (auto i : cube.mass)
		std::cout << i << " ";

	return 0;
}