#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("None")
{
	std::cout << "WrongAnimal constructor called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	std::cout << "WrongAnimal copy constructor called.\n";
	this->setType(ref.getType());
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called.\n";
}

WrongAnimal&		WrongAnimal::operator=(const WrongAnimal& ref)
{
	if (this != &ref)
		this->setType(ref.getType());
	return *this;
}

std::string	WrongAnimal::getType() const
{
	return this->_type;
}

void		WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

void		WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal sound!\n";
}
