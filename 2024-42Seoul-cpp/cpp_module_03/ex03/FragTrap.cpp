#include "FragTrap.hpp"
#include <iostream>

const int FragTrap::_unitHP = 100;
const int FragTrap::_unitEP = 100;
const int FragTrap::_unitAD = 30;

FragTrap::FragTrap() : ClapTrap("FragTrap", _unitHP, _unitEP, _unitAD)
{
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name, _unitHP, _unitEP, _unitAD)
{
	std::cout << "FragTrap constructor callled" << std::endl;
}

FragTrap::FragTrap(FragTrap const &fragTrap) : ClapTrap(fragTrap)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &fragTrap)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	ClapTrap::operator=(fragTrap);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
}