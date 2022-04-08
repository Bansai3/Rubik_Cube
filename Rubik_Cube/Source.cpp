#include "Cube.h"


int main()
{
	std::string filename = "cube_state.in";
	Cube cube;
	cube.load_from_file(filename);
	cube.Mixing();
	std::cout << cube;
	return 0;
}