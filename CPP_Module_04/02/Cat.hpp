#ifndef Cat_HPP
#define Cat_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
	Brain *brain;

	public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	void	makeSound() const;
	void	setIdea(const std::string idea);
	void	getIdeas();
};

std::ostream& operator<<(std::ostream& os, const Cat& fixed);

#endif


