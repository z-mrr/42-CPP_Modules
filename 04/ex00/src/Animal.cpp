#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("None")
{
	std::cout << "Animal constructor called.\n";
}

Animal::Animal(const Animal &ref)
{
	std::cout << "Animal copy constructor called.\n";
	*this = ref;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called.\n";
}

Animal&		Animal::operator=(const Animal& ref)
{
	if (this != &ref)
		this->type = ref.getType();
	return *this;
}

std::string	Animal::getType() const
{
	return this->type;
}

void	Animal::setType(std::string type)
{
	this->type = type;
}

void		Animal::makeSound() const
{
	std::cout << "Not sure what sound to make!\n";
}
