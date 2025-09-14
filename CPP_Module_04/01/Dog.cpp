#include "Dog.hpp"

Dog::Dog(): Animal(){
	type = "Dog";
	this->brain = new Brain("Dog");
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other):Animal(other) {
	this->brain = new Brain(*(other.brain));
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog copy asigament constructor called" << std::endl;
	if (this != &other){
		delete this->brain;
		this->brain = new Brain(*(other.brain));
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(){
	std::cout << "Woof! Woof!" << std::endl;

}

void  Dog::setIdea(const std::string idea){
	this->brain->setIdea(idea);
}

void Dog::getIdeas(){
	this->brain->getIdeas();
}

std::ostream& operator<<(std::ostream& os, const Dog& fixed){
	os << fixed.getType();
	return os;
}
