#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(std::string const &type);
	WrongAnimal(WrongAnimal const &wrongAnimal);
	WrongAnimal &operator=(WrongAnimal const &wrongAnimal);
	~WrongAnimal();

	std::string getType() const;
	void makeSound() const;
};

#endif // WRONG_ANIMAL_HPP