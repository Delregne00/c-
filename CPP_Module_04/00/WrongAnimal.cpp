#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	std::cout << "WrongAnimal " << type << " is created called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) {
	this->type = type;
	std::cout << "WrongAnimal " << type << " is created called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "Copy constructor called" << std::endl;
	this->type = other.type;
	std::cout << "WrongAnimal " << type << " is created" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
	std::cout << "Copy asigament constructor called" << std::endl;
	if (this != &other){
		this->type = other.type;
	}
	std::cout << "WrongAnimal " << type << " is created" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal " << type << " is destroyed" << std::endl;
}

void WrongAnimal::makeSound(){
	std::cout << "WrongAnimal " << type << " makes a general sound" << std::endl;
}

void WrongAnimal::setType(const std::string name){
	type = name;
}

std::string WrongAnimal::getType() const {
	return type;
}

std::ostream& operator<<(std::ostream& os, const WrongAnimal& fixed){
	os << fixed.getType();
	return os;
}
