#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *materias[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource const &materiaSource);
	MateriaSource &operator=(MateriaSource const &materiaSource);
	~MateriaSource();

	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);
};

#endif // MATERIASOURCE_HPP