#include <vector>
#include <iostream>
#include "easyFind.hpp"

int main(){
	std::vector<int> arr;

	arr.push_back(0);
	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);

	std::cout << "Number 0 is in array: ";
	try{
		std::cout << easyfind(arr, 0) << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "Number 20 is in array: ";
	try{
		std::cout << easyfind(arr, 20) << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "Number 50 is in array: ";
	try{
		std::cout << easyfind(arr, 50) << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}
