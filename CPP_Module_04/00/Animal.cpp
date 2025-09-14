#include "Animal.hpp"

Animal::Animal() : type("Default") {
	std::cout << "Animal default constructor called" << std::endl;
	std::cout << "Animal " << type << " is created called" << std::endl;
}

Animal::Animal(const std::string &type) {
	this->type = type;
	std::cout << "Animal " << type << " is created called" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Copy constructor called" << std::endl;
	this->type = other.type;
	std::cout << "Animal " << type << " is created" << std::endl;
}

Animal &Animal::operator=(const Animal &other){
	std::cout << "Copy asigament constructor called" << std::endl;
	if (this != &other){
		this->type = other.type;
	}
	std::cout << "Animal " << type << " is created" << std::endl;
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal " << type << " is destroyed" << std::endl;
}

void Animal::makeSound(){
	std::cout << "Animal " << type << " makes a general sound" << std::endl;
}

void Animal::setType(const std::string name){
	type = name;
}

std::string Animal::getType() const {
	return type;
}

std::ostream& operator<<(std::ostream& os, const Animal& fixed){
	os << fixed.getType();
	return os;
}
