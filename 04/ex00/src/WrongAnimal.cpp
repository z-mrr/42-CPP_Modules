#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("None")
{
	std::cout << "WrongAnimal constructor called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	std::cout << "WrongAnimal copy constructor called.\n";
	*this = ref;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called.\n";
}

WrongAnimal&		WrongAnimal::operator=(const WrongAnimal& ref)
{
	if (this != &ref)
		this->type = ref.getType();
	return *this;
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}

void		WrongAnimal::setType(std::string type)
{
	this->type = type;
}

void		WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal sound!\n";
}
