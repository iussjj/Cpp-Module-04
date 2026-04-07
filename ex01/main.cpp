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
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
	}

	std::cout << "\nDEEP COPY TESTS:\n" << std::endl;
	std::cout << "CREATING ORIGINAL DOG:" << std::endl;
	Dog	originalDog;
	/*
		If tmp would be a shallow copy, it wouldn't have a separate
		brain from originalDog, and closing the scope block would
		delete originalDog's brain too. This would trigger a double
		free error once main has completed and originalDog is cleaned up.
	*/
	{
		std::cout << "\nCREATING COPY DOG:" << std::endl;
		Dog copy = originalDog;
		std::cout << "\nDELETING COPY DOG:" << std::endl;
	} 
	std::cout << "\nCHECKING ORIGINAL DOG'S BRAIN:" << std::endl;
	originalDog.getBrain()->setIdea(0, "I'm hungry!\n");
	std::cout << originalDog.getBrain()->getIdea(0) << std::endl;
	/*
		If the copy had been shallow, originalDog's brain would have
		been deleted and trying to access it would have caused a 
		segfault.
	*/
	std::cout << "DELETING ORIGINAL DOG:" << std::endl;
	return 0;
}