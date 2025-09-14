#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"



int main()
{
	std::cout << "\n=== POLIMORFISM ===" << std::endl;

	Animal *animal = new Animal();
	Animal *lassy = new Dog();
	Animal *missifu = new Cat();

	std::cout << "\n=== ANIMAL ===" << std::endl;
	std::cout << "Animal object type : "<< animal->getType() << std::endl;
	animal->makeSound();

	std::cout << "\n=== DOG ===" << std::endl;
	std::cout << "Dog object type : "<< lassy->getType() << std::endl;
	lassy->makeSound();

	std::cout << "\n=== CAT ===" << std::endl;
	std::cout << "Cat object type : "<< missifu->getType() << std::endl;
	missifu->makeSound();

	Dog myDog;
	Cat myCat;

	std::cout << "\n=== TESTING BRAINS ===" << std::endl;

	myDog.setIdea("Chase cats");
	for (int i = 0; i < 100; i++)
		myDog.setIdea("Fetch ball");
	myDog.getIdeas();

	myCat.setIdea("Sleep all day");
	myCat.setIdea("Hunt mice");
	myCat.getIdeas();

	std::cout << "\n=== DESTRUCTIoN ===" << std::endl;
	delete missifu;
	delete lassy;
	delete animal;

	std::cout << "\n=== ARRAY TEST ===" << std::endl;

	Animal *manade[100];

	for (int i = 0; i < 100; i++){
		if (i < 50)
			manade[i] = new Dog();
		else
			manade[i] = new Cat();
	}

	for (int i = 0; i < 100; i++)
		delete manade[i];

	std::cout << "\n=== DEEP COPY ===" << std::endl;

	Dog original;
	original.setIdea("Original idea");
	std::cout << "Original after adding idea:" << std::endl;
	original.getIdeas();

	Dog copia = original;  // Constructor de copia
	std::cout << "Copy immediately after creation:" << std::endl;
	copia.getIdeas();  // ¿Tiene la misma idea?

	copia.setIdea("Copy-only idea");
	std::cout << "After modifying copy:" << std::endl;
	std::cout << "Original:" << std::endl;
	original.getIdeas();
	std::cout << "Copy:" << std::endl;
	copia.getIdeas();

	return 0;

}
