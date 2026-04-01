#pragma once

#include <iostream>

/*
	The virtual keyword tells the compiler, "Hey, look at this
	object at runtime and figure out what its true type is."

	! Constructors are NEVER virtual
	! Copy assignment operator can, but SHOULD NEVER be
	! Destructors ALWAYS are

	*Default Member Initialization (or In-class Member Initialization):
	*since C++ 11, member fields can be initialized in the class
	*definition: std::string	type = "Critter";
*/

class Animal
{
protected:
	std::string	type = "Critter";

public:
	Animal();
	Animal(const Animal &source);
	Animal &operator=(const Animal &source);
	virtual ~Animal();

//	Need to be const to work with const Animal objects!
	std::string		getType(void) const;
	virtual void	makeSound(void) const;
};