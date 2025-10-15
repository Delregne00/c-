#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "\n=== POLIMORFISM ===" << std::endl;

	Animal *animal = new Animal();
	Animal *dog = new Dog();
	Animal *cat = new Cat();

	std::cout << "\n=== ANIMAL ===" << std::endl;
	std::cout << "Animal object type : "<< animal->getType() << std::endl;

	std::cout << "\n=== DOG ===" << std::endl;
	std::cout << "Dog object type : "<< dog->getType() << std::endl;
	dog->makeSound();

	std::cout << "\n=== CAT ===" << std::endl;
	std::cout << "Cat object type : "<< cat->getType() << std::endl;
	cat->makeSound();

	std::cout << "\n=== DESTRUCTIoN ===" << std::endl;
	delete cat;
	delete dog;
	delete animal;

	return 0;
}
