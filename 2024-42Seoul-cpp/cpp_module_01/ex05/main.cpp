#include "Harl.hpp"
#include <iostream>

int main() {
	Harl harl = Harl();
	while (1)
	{
		std::cout << "Plesae enter a level: ";
		std::string level;
		std::cin >> level;
		harl.complain(level);
	}
	return (0);
}
