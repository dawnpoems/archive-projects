#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(std::string const &name);
	DiamondTrap(DiamondTrap const &diamondTrap);
	DiamondTrap &operator=(DiamondTrap const &diamondTrap);
	~DiamondTrap();

	void whoAmI();
	void attack(std::string const &target);
};

#endif // DIAMOND_TRAP_HPP