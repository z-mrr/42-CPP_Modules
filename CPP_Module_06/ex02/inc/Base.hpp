#ifndef BASE_CPP
#define BASE_CPP

#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;

class Base
{
public:
	virtual ~Base() {};

	static Base*	generate();
	static void		identify(Base* p);
	static void		identify(Base& p);
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif
