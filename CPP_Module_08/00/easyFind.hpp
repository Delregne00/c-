#include <vector>
#include <iostream>

class NotFoundException : public std::exception{
public:
	const char *what() const throw(){
		return "Value not found in container";
	}
};

template <typename T>
int easyfind(T &container, int value){
	for (unsigned int  i = 0; i < container.size(); i++){
		if (container[i] == value)
			return i;
	}
	throw NotFoundException();
}
