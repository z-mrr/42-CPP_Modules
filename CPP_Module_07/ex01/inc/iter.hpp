#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

using std::cout;

// teria que especificar o tipo da func na call da main

// template<typename T, typename Func>
// void	iter(T* arr, size_t size, Func f) {
// 	for (size_t i = 0; i < size; i++) {
// 		f(arr[i]);
// 	}
// }

template<typename T>
void	iter(T* arr, size_t size, void (*f)(T const&)) {
	for (size_t i = 0; i < size; i++) {
		f(arr[i]);
	}
}

template<typename T>
void printValue(T val)
{
	cout << val;
}

#endif
