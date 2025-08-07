#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("FragTrap", 100, 100, 30)
{
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap constructor called" << std::endl;
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