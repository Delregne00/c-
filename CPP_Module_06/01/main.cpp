#include "Serializer.hpp"

int main()
{
	Data originalData;

	originalData.name = "Direction";
	originalData.id = 42;
	originalData.country = "Spain";
	originalData.city = "Flix";
	originalData.adress = "Amassadora n16";

	std::cout << "DATA:" << std::endl << std::endl;
	std::cout << "Pointer Data structure: " << &originalData << std::endl;
	std::cout << "ID: " << originalData.id << std::endl;
	std::cout << "Name: " << originalData.name << std::endl;
	std::cout << "Country: " << originalData.country<< std::endl;
	std::cout << "City: " << originalData.city<< std::endl;
	std::cout << "Adress: " << originalData.adress<< std::endl << std::endl;

	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "Serialized data: " << serialized << std::endl<< std::endl;

	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized:" << std::endl;
	std::cout << "Pointer Data structure: " << deserialized << std::endl;
	std::cout << "ID: " << deserialized->id << std::endl;
	std::cout << "Name: " << deserialized->name << std::endl;
	std::cout << "Country: " << deserialized->country << std::endl;
	std::cout << "City: " << deserialized->city << std::endl;
	std::cout << "Adress: " << deserialized->adress << std::endl;

	return 0;
}
