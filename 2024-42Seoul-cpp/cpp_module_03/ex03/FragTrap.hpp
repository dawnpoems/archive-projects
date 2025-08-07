#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	/* data */
public:
	FragTrap();
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &fragTrap);
	FragTrap &operator=(FragTrap const &fragTrap);
	~FragTrap();

	void highFivesGuys(void);
	
	static const int _unitHP;
	static const int _unitEP;
	static const int _unitAD;
};

#endif // FRAG_TRAP_HPP