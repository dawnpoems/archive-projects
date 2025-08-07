#include <iostream>
#include "Zombie.hpp"

int main() {
	std::cout << "----Creating a Zombie on the heap----" << std::endl;
	Zombie* zombie = newZombie("Heap Zombie");
	std::cout << "----Announcing the Zombie on the heap----" << std::endl;
	zombie->announce();

	std::cout << "----Creating a Zombie on the stack----" << std::endl;
	randomChump("Stack Zombie");

	std::cout << "----Deleting the Zombie on the heap----" << std::endl;
	delete zombie;
	std::cout << "----main function ends----" << std::endl;
	return 0;
}
