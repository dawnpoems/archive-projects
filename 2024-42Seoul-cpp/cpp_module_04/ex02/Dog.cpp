#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(Dog const &dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*dog.brain);
}

Dog &Dog::operator=(Dog const &dog)
{
	std::cout << "Dog assignation operator called" << std::endl;
	Animal::operator=(dog);
	delete brain;
	brain = new Brain(*dog.brain);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "GRRRRRRRRRRRRRR!!!" << std::endl;
}