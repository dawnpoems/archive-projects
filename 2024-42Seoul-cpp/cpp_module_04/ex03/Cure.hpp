#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	/* data */
public:
	Cure();
	Cure(Cure const &cure);
	Cure &operator=(Cure const &cure);
	~Cure();

	void use(ICharacter &target);
	AMateria *clone() const;
};


#endif // CURE_HPP