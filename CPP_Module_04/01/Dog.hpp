#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
	Brain *brain;

	public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	void	makeSound();
	void	setIdea(const std::string idea);
	void	getIdeas();
};

std::ostream& operator<<(std::ostream& os, const Dog& fixed);

#endif


