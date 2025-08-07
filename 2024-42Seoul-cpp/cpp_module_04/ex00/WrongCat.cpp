#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &wrongCat) : WrongAnimal(wrongCat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &wrongCat)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	WrongAnimal::operator=(wrongCat);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}