#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type("Normal")
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria(AMateria const &amateria) : type(amateria.getType())
{
}

AMateria &AMateria::operator=(AMateria const &amateria)
{
	if (this->type != amateria.getType())
	{
		std::cout << "Different types of Materia cannot be assigned." << std::endl;
	}
	return *this;
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}