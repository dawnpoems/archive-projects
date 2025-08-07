#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap
{
protected:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string const &name);
	ClapTrap(std::string const &name, int hitPoints, int energyPoints, int attackDamage);
	ClapTrap(ClapTrap const &clapTrap);
	ClapTrap &operator=(ClapTrap const &clapTrap);
	~ClapTrap();

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif // CLAP_TRAP_HPP