#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &dog)
{
	std::cout << "Dog assignation operator called" << std::endl;
	Animal::operator=(dog);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "GRRRRRRRRRRRRRR!!!" << std::endl;
}