#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(Cat const &cat) : Animal(cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*cat.brain);
}

Cat &Cat::operator=(Cat const &cat)
{
	std::cout << "Cat assignation operator called" << std::endl;
	Animal::operator=(cat);
	delete brain;
	brain = new Brain(*cat.brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "MEOWRR!" << std::endl;
}