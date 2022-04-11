#include "Cube.h"
#include <iostream>
#include <set>
#include <algorithm>


int main()
{
	std::string filename = "cube_state.in";
	Cube cube;
	cube.LoadFromFile(filename);

	std::set<long long> s;
	for (size_t i = 0; i < 6000; i++)
	{
		cube.Mixing();
		long long h1 = cube.getHash();
		if (std::find(s.begin(), s.end(), h1) != s.end())
			std::cout << "COPY!\n";
		else
			std::cout << h1 << "\n";
		s.insert(h1);
	}
	std::cout << s.size() << std::endl;
	std::cout << cube;
	std::cout << cube.checkState();
	return 0;
}