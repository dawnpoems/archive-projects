#include <iostream>
#include "DiamondTrap.hpp"
#include <sstream>

std::string intToString(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

int main( void ) {

	std::cout << "-------------------Energy points From ScavTrep(50)----------------------" << std::endl;
	std::cout << "-------------------Attack damage From FragTrep(30)----------------------" << std::endl;

	DiamondTrap diamondtrap1("diamond1");

	for (int i = 0; i < 30; i++)
	{
		diamondtrap1.attack("You" + intToString(i));
		diamondtrap1.beRepaired(5);
	}

	std::cout << "-------------------Hit points From FlagTrep(100)----------------------" << std::endl;

	DiamondTrap diamondtrap2("diamond2");

	diamondtrap2.takeDamage(90);
	diamondtrap2.attack("You");
	diamondtrap2.takeDamage(10);
	diamondtrap2.attack("You");

	std::cout << "----------------------------------------------------------------------" << std::endl;
	diamondtrap1.guardGate();
	diamondtrap1.highFivesGuys();
	diamondtrap1.whoAmI();

	return 0;
}