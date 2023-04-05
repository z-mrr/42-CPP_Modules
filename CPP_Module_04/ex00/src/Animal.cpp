#include "Animal.hpp"

Animal::Animal() : _type("None")
{
	std::cout << "Animal constructor called.\n";
}

Animal::Animal(const Animal &ref) : _type(ref.getType())
{
	std::cout << "Animal copy constructor called.\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called.\n";
}

Animal&		Animal::operator=(const Animal& ref)
{
	if (this != &ref)
		this->_type = ref.getType();
	return *this;
}

std::string	Animal::getType() const
{
	return this->_type;
}

void	Animal::setType(std::string type)
{
	this->_type = type;
}

void		Animal::makeSound() const
{
	std::cout << "Not sure what sound to make!\n";
}
