#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

/*
	In child classes, inherited member variables can't be set with
	initialization lists! Standard practice is to call the base class
	constructor
*/

Cat::Cat(const Cat &source) : Animal(source)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

/*
	Since Cat has no unique non-inherited variables, calling the
	base class copy assignment operator works. Unique variables
	would need to be manually copied next.
*/

Cat& Cat::operator=(const Cat &source)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &source)
	{
		Animal::operator=(source);
		//this->type = source.type;
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}