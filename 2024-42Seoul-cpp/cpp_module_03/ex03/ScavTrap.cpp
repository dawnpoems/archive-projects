#include "ScavTrap.hpp"
#include <iostream>

const int ScavTrap::_unitHP = 100;
const int ScavTrap::_unitEP = 50;
const int ScavTrap::_unitAD = 20;

ScavTrap::ScavTrap() : ClapTrap("ScavTrap", _unitHP, _unitEP, _unitAD)
{
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name, _unitHP, _unitEP, _unitAD)
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