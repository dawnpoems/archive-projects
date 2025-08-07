#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A zombie is born." << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << this->name << " is born." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is dead." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
