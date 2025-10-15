#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other):WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	std::cout << "WrongCat copy asigament constructor called" << std::endl;
	if (this != &other){
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(){
	std::cout << "Miau" << std::endl;

}

std::ostream& operator<<(std::ostream& os, const WrongCat& fixed){
	os << fixed.getType();
	return os;
}
