#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {

	ClapTrap claptrap("myTrap");

	claptrap.attack("You1");
	claptrap.attack("You2");
	claptrap.attack("You3");
	claptrap.attack("You4");
	claptrap.attack("You5");
	claptrap.takeDamage(9);
	claptrap.beRepaired(5);
	claptrap.beRepaired(5);
	claptrap.beRepaired(5);
	claptrap.beRepaired(5);
	claptrap.beRepaired(5);

	std::cout << "----------------------used all energy---------------------------" << std::endl;
	
	claptrap.attack("You6");
	claptrap.beRepaired(5);

	return 0;
}