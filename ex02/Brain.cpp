#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &source)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = source.ideas[i];
	}
}

/*
	Can't use an initialization list here, since raw arrays can't be
	copied. The only option is to copy the contents index by index.
*/

Brain& Brain::operator=(const Brain &source)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &source)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = source.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index >= 0 && index < 100)
	{
		this->ideas[index] = idea;
	}
}

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return this->ideas[index];
	}
	return "";
}