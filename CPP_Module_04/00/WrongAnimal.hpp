#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
	protected:
	std::string type;

	public:
	WrongAnimal();
	WrongAnimal(const std::string &name);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	~WrongAnimal();

	std::string		getType() const;
	void			setType(const std::string name);
	void	makeSound();
};

std::ostream& operator<<(std::ostream& os, const WrongAnimal& fixed);

#endif


