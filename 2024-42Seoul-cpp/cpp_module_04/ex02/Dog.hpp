#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog();
	Dog(Dog const &dog);
	Dog &operator=(Dog const &dog);
	~Dog();

	void makeSound() const;
};

#endif // DOG_HPP