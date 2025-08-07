#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	/* data */
public:
	Ice();
	Ice(Ice const &ice);
	Ice &operator=(Ice const &ice);
	~Ice();

	void use(ICharacter &target);
	AMateria *clone() const;
};


#endif // ICE_HPP