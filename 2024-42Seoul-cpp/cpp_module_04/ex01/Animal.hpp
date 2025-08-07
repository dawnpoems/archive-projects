#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string const &type);
	Animal(Animal const &animal);
	Animal &operator=(Animal const &animal);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};

#endif