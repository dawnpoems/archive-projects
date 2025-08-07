#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	/* data */
public:
	ScavTrap();
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &clapTrap);
	ScavTrap &operator=(ScavTrap const &clapTrap);
	~ScavTrap();

	void guardGate();
	void attack(std::string const &target);
};

#endif