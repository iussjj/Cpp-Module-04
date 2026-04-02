#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

/*
	In child classes, inherited member variables can't be set with
	initialization lists! Standard practice is to call the base class
	constructor
*/

Dog::Dog(const Dog &source) : Animal(source)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

/*
	Since Dog has no unique non-inherited variables, calling the
	base class copy assignment operator works. Unique variables
	would need to be manually copied next.
*/

Dog& Dog::operator=(const Dog &source)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &source)
	{
		Animal::operator=(source);
		//this->type = source.type;
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof!" << std::endl;
}