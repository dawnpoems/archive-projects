#include "Character.hpp"

Character::Character() : name("NoName")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const &character)
{
	for (int i = 0; i < 4; i++)
	{
		if (character.inventory[i])
			this->inventory[i] = character.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character &Character::operator=(Character const &character)
{
	if (this != &character)
	{
		this->name = character.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];

			if (character.inventory[i])
				this->inventory[i] = character.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (0 <= idx && idx < 4 && this->inventory[idx])
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (0 <= idx && idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
}