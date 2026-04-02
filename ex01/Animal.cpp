#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
	std::cout << "Animal constructor called" << std::endl;
}

// Set copy type with an initialization list, not a copy assignment

Animal::Animal(const Animal &source) : type(source.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &source)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
	}
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::makeSound(void) const
{
	std::cout << "*critter sounds*" << std::endl;
}