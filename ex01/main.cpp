#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

int main()
{
	Animal* animals[10];
	for (int i = 0; i < 5; i++)
	{
		animals[i] = new Dog();
		animals[i + 5] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout	<< i << ":"
					<< " The " << animals[i]->getType()
					<< " says ";
		animals[i]->makeSound();
	}
	delete animals;
	return 0;
}