#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
	if (weapon == NULL)
	{
		std::cout << this->name << " attacks with his fist" << std::endl;
	}
	else
	{
		std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
	}
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
