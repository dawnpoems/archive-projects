#include "Brain.hpp"

#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = brain.ideas[i];
	}
}

Brain &Brain::operator=(Brain const &brain)
{
	std::cout << "Brain assignation operator called" << std::endl;
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = brain.ideas[i];
        }
    }
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
	if (0 <= index && index < 100)
	{
		this->ideas[index] = idea;
	}
}

std::string Brain::getIdea(int index) const
{
	if (0 <= index && index < 100)
	{
		return (this->ideas[index]);
	}
	return ("");
}
