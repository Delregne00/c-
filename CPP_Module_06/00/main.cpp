#include "ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		std::cerr << "Usage: ./converter <value>" << std::endl;
		std::cerr << "Accepted types: char, int, float, double" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
	return 0;
}
