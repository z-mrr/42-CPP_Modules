#ifndef SERIALIZER_CPP
#define SERIALIZER_CPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>
// typedef unsigned long uintptr_t;

using std::string;
using std::cout;

class Serializer
{
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
private:
	Serializer();
	Serializer(const Serializer&);
	~Serializer();
	Serializer&	operator=(const Serializer&);
};

#endif
