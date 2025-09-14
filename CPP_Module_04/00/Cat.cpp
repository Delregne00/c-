#include "Cat.hpp"

Cat::Cat(): Animal()  {
	type = "Cat";
	this->brain = new Brain("Cat");
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other):Animal(other) {
	this->brain = new Brain("Cat");
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Cat copy asigament constructor called" << std::endl;
	if (this != &other){
		delete this->brain;
		this->brain = new Brain(*(other.brain));
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(){
	std::cout << "Miau" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Cat& fixed){
	os << fixed.getType();
	return os;
}
