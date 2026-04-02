#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << "Wrong animal tests:" << std::endl;
	const WrongAnimal* shub_niggurath = new WrongAnimal();
	const WrongAnimal* garfield = new WrongCat();
	std::cout << shub_niggurath->getType() << " " << std::endl;
	std::cout << garfield->getType() << " " << std::endl;
	shub_niggurath->makeSound();
	garfield->makeSound();
	/*
		If the WrongAnimal destructor was non-virtual, the following
		delete statement would cause undefined behavior and a possible
		partial memory leak, since only the base class part of the object
		would be deleted. With a virtual destructor, the base and child
		parts are deleted.
	*/
	delete shub_niggurath;
	delete garfield;
	return 0;
}