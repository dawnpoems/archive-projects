#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main()
{
	const int arraySize = 10;
	Animal* animals[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
		{
			animals[i] = new Dog();
		}
		else
		{
			animals[i] = new Cat();
		}
	}

	std::cout << "----------Every Animal Created------------" << std::endl;

	for (int i = 0; i < arraySize; i++)
	{
		delete animals[i];
	}

	// Animal *animal = new Animal();
	// 순수 가상 함수가 존재하여 생성이 불가능하다.

	return 0;
}