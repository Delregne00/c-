#include "Span.hpp"

Span::Span(): _arr(0), _size(0) {}

Span::Span(const Span &other): _arr(other._arr), _size(other._size) {}

Span::Span(unsigned int size): _arr(0), _size(size) {}

Span &Span::operator=(const Span &other){
	if (this != &other){
		_size = other._size;
		for (unsigned int i = 0; i < other._size; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

Span::~Span(){}

const char *Span::OutOfRangeException::what() const throw(){
	return "the array is completed";
}

const char *Span::NotFoundNumberException::what() const throw(){
	return "Not find the numbeer in the array";
}

void Span::addNumber(int n){
	if (_arr.size() < _size)
		_arr.push_back(n);
	else
		throw OutOfRangeException();
}


//Falta short y long , tinc que mirar la diferncia mes gran o la mes petita dela array
