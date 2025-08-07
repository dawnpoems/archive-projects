#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("ScavTrap", 100, 50, 20)
{
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &scavTrap)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	ClapTrap::operator=(scavTrap);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no energy points left!" << std::endl;
		return ;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no hit points left!" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode!" << std::endl;
}