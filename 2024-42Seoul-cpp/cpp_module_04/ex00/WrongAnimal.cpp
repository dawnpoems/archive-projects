#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type) : type(type)
{
	std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrongAnimal) : type(wrongAnimal.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &wrongAnimal)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	this->type = wrongAnimal.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}