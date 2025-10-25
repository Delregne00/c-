#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array{
private:
	T	*_arr;
	unsigned int _size;

public:
	Array(): _arr(NULL), _size(0) {}

	Array(unsigned int n): _arr(NULL), _size(n){
		_arr = new T[n];
	}

	Array(const Array<T> &other): _arr(NULL), _size(other._size){
		_arr = new T[_size];
	}

	Array &operator=(const Array<T> &other){
		if (this != &other){
			delete[] _arr;
			_size = other._size;
			_arr = new T[_size];
			for (int i = 0; i < _size; i++)
				_arr[i] = other._arr[i];
		}
		return *this;
	}

	~Array(){
		delete[] _arr;
	}

	class OutOfIndexException : public::std::exception{
		const char *what() const throw(){
			return "Out of range of index";
		}
	};

	unsigned int size() const{
		return _size;
	}
	T &operator[](unsigned int index){
		if (index >= _size)
			throw OutOfIndexException();
		else
			return _arr[index];
	}

};

#endif
