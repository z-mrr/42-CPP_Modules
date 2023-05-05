#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <sstream>

using std::cout;

template<typename T>
std::string convertToString(const T& value) {
	std::ostringstream o;
	o << value;
	return o.str();
}

template<typename T>
class Array {
public:
	Array() : _size(0), _arr(NULL) {};
	Array(unsigned int n) : _size(n), _arr(new T[n]) {
		for (unsigned int i = 0; i < n; i++) {
			_arr[i] = T();
		}
	}
	Array(Array const& other) : _size(other._size), _arr(new T[other._size]) {
		for (unsigned int i = 0; i < other._size; i++) {
			this->_arr[i] = other._arr[i];
		}
	}
	~Array() {
		if (_arr)
			delete[] _arr;
	}
	Array&	operator=(Array const& other) {
		if (this != &other) {
			delete[] this->_arr;
			this->_size = other._size;
			this->_arr = new T[this->_size];
			for (unsigned int i = 0; i < other._size; i++) {
				this->_arr[i] = other._arr[i];
			}
		} return *this;
	}
	T&	operator[](unsigned int index) const {
		if (index >= this->_size)
			throw std::out_of_range("Index out of range: " + convertToString(index));
		return this->_arr[index];
	}
	unsigned int	size() const {return this->_size;}


private:
	unsigned int	_size;
	T*				_arr;
};

#endif
