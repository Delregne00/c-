#include <iostream>
#include <cstddef>
#include "iter.hpp"


int main(){
	std::string arr = {'A', 'B', 'C'};

	iter(&arr, arr.size(), imprimir<char>);

}
