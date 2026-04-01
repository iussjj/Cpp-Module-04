#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

// Set copy type with an initialization list, not a copy assignment

WrongCat::WrongCat(const WrongCat &source) : WrongAnimal(source)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &source)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &source)
	{
		WrongAnimal::operator=(source);
	}
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "!woɘM" << std::endl;
}