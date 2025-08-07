#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cout << "Plesae enter a level" << std::endl;
		return (1);
	}
	Harl harl = Harl();
	std::string level(argv[1]);
	harl.complain(level);
	return (0);
}
