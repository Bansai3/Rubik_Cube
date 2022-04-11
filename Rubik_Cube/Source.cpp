#include "Cube.h"
#include <set>


int main()
{
	std::string filename = "cube_state.in";
	Cube cube;
	cube.load_from_file(filename);
	cube.Mixing();
	std::cout << cube;
	//std::cout << cube.checkState();
	return 0;
}