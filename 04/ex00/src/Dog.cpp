#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called.\n";
	this->setType("Dog");
}

Dog::Dog(const Dog &ref) : Animal()
{
	std::cout << "Dog copy constructor called.\n";
	*this = ref;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called.\n";
}

Dog&	Dog::operator=(const Dog& ref)
{
	if (this != &ref)
		this->type = ref.getType();
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Auf auf!\n";
}
