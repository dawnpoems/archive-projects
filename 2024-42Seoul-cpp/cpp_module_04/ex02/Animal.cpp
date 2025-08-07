#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string const &type) : type(type)
{
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(Animal const &animal) : type(animal.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &animal)
{
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = animal.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}