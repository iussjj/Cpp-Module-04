#pragma once

#include <iostream>
#include <string>


class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain &source);
	Brain &operator=(const Brain &source);
	~Brain();

	void 		setIdea(int index, std::string idea);
	std::string	getIdea(int index) const;
};