#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

/*
	In child classes, inherited member variables can't be set with
	initialization lists! Standard practice is to call the base class
	constructor
*/

Cat::Cat(const Cat &source) : Animal(source)
{
	std::cout << "Cat copy constructor called" << std::endl;
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

Cat& Cat::operator=(const Cat &source)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &source)
	{
		Animal::operator=(source);
		*this->brain = *source.brain;
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return this->brain;
}