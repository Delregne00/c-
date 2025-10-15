#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(){
	WrongAnimal *cat = new WrongCat();

	cat->makeSound();

	delete cat;
	return 0;

}
