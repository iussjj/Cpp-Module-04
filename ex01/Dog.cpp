#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

/*
	In child classes, inherited member variables can't be set with
	initialization lists! Standard practice is to call the base class
	constructor
*/

Dog::Dog(const Dog &source) : Animal(source)
{
	std::cout << "Dog copy constructor called" << std::endl;
	/*
		The brain index copying logic is implemented in the brain
		copy constructor, and does not need to be repeated here! :)
	*/
	this->brain = new Brain(*source.brain);
}

/*
	Inherited variables from the base class are copied with the base
	class operator. Variables specific to child classes are copied manually,
	or in this case with the Brain copy assignment operator. Dereference
	both to get the object itself, not memory addresses!
*/

Dog& Dog::operator=(const Dog &source)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &source)
	{
		Animal::operator=(source);
		*this->brain = *source.brain;
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof!" << std::endl;
}