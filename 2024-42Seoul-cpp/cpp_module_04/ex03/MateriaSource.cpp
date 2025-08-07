#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &materiaSource)
{
	if (this != &materiaSource)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materiaSource.materias[i])
				this->materias[i] = materiaSource.materias[i]->clone();
			else
				this->materias[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &materiaSource)
{
	if (this != &materiaSource)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->materias[i])
				delete materias[i];

			if (materiaSource.materias[i])
				this->materias[i] = materiaSource.materias[i]->clone();
			else
				this->materias[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])
			delete this->materias[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->materias[i])
		{
			this->materias[i] = materia;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materias[i] && this->materias[i]->getType() == type)
			return this->materias[i]->clone();
	}
	return 0;
}