#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
	/* data */
public:
	WrongCat();
	WrongCat(WrongCat const &wrongCat);
	WrongCat &operator=(WrongCat const &wrongCat);
	~WrongCat();

	void makeSound() const;
};

#endif // WRONG_CAT_HPP