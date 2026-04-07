#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

/*
	The virtual keyword tells the compiler, "Hey, look at this
	object at runtime and figure out what its true type is."

	! Constructors are NEVER virtual
	! Copy assignment operator can, but SHOULD NEVER be
	! Destructors ALWAYS are

	*Default Member Initialization (or In-class Member Initialization):
	*since C++ 11, member fields can be initialized in the class
	*definition: std::string	type = "Critter";

	In a child class, this can't be used! Doing so would cause 
	variable shadowing: The object would have a type var associated
	with the base class initialized to "Critter" and a new type
	var associated with the child class! The new value must be
	set in the actual constructor implementation.
*/

class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat &source);
	Cat &operator=(const Cat &source);
	~Cat() override;

//	Need to be const to work with const Cat objects!
	void	makeSound(void) const override;
	Brain*	getBrain(void) const;
};