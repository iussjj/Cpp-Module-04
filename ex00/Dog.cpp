#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
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

Dog& Dog::operator=(const Dog &source)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
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