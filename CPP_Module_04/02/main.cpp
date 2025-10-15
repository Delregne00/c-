#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"



int main()
{
	Animal *dog = new Dog();
	Animal *cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	delete	cat;


	return 0;

}
