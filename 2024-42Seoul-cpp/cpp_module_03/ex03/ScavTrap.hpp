#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
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

	static const int _unitHP;
	static const int _unitEP;
	static const int _unitAD;
};

#endif