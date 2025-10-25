#include "Span.hpp"

int main(){
	Span arr(6);

	for(unsigned int i = 0; i < 9; i++){
		try{
			arr.addNumber(i * i);
		}
		catch(const std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "Number 3 shortposition: 4 " << std::endl;
	try{
		std::cout <<"Test shortPosition: " << arr.shortestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Number 4 longPosition: 2 " << std::endl;
	try{
		std::cout << "test longPosition: " << arr.longestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Number 10 longPosition: EXCEPTION " << std::endl;
}
