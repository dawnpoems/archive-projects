#include "Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const &cure) : AMateria(cure)
{
}

Cure &Cure::operator=(Cure const &cure)
{
	AMateria::operator=(cure);
	return *this;
}

Cure::~Cure()
{
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}