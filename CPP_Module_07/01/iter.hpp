#pragma once

#include <iostream>
#include <array>

template <typename T, typename Func>
void iter(T *ptr, size_t size, Func func){
	for (size_t i = 0; i < size; i++)
		func(ptr[i]);
}

template <typename T>
void imprimir(T elemento){
	std::cout << elemento << " ";
}
