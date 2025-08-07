#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <sstream>

std::string intToString(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

int main( void ) {

	FragTrap fragtrap("frag");

	for (int i = 0; i < 60; i++)
	{
		fragtrap.attack("You" + intToString(i));
		fragtrap.beRepaired(5);
	}
	
	fragtrap.takeDamage(10);
	fragtrap.highFivesGuys();

	return 0;
}