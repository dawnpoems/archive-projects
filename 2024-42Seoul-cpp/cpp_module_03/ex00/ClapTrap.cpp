#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clapTrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &clapTrap)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
		return ;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no hit points left!" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
		return ;
	}
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no hit points left!" << std::endl;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points!" << std::endl;
}
