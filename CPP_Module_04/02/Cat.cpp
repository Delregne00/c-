#include "Cat.hpp"

Cat::Cat(): Animal(){
	type = "Cat";
	this->brain = new Brain("Cat");
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other):Animal(other) {
	this->brain = new Brain(*(other.brain));
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
	std::cout << "Cat destructor called" << std::endl;
		delete this->brain;
}

void Cat::makeSound() const {
	std::cout << "Miau" << std::endl;

}

void  Cat::setIdea(const std::string idea){
	this->brain->setIdea(idea);
}

void Cat::getIdeas(){
	this->brain->getIdeas();
}


std::ostream& operator<<(std::ostream& os, const Cat& fixed){
	os << fixed.getType();
	return os;
}
