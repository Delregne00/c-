#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
	protected:
	std::string type;

	public:
	Animal();
	Animal(const std::string &name);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	std::string		getType() const;
	void			setType(const std::string name);
	virtual void	makeSound() const = 0;
};

std::ostream& operator<<(std::ostream& os, const Animal& fixed);

#endif


