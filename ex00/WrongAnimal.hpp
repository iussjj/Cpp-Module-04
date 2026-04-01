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

class WrongAnimal
{
protected:
	std::string	type = "Eldritch Horror";

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &source);
	WrongAnimal &operator=(const WrongAnimal &source);
	~WrongAnimal();

/*
	Intentionally broken polymorphism: no virtual keywords!
	This will bind all base class pointer objects to use
	base class functions, so a WrongCat will still output
	the WrongAnimal sound!
*/
	std::string		getType(void) const;
	void			makeSound(void) const;
};