#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called.\n";
	this->setType("Dog");
}

Dog::Dog(const Dog &ref) : Animal()
{
	std::cout << "Dog copy constructor called.\n";
	this->setType(ref.getType());
}

Dog::~Dog()
{
	std::cout << "Dog destructor called.\n";
}

Dog&	Dog::operator=(const Dog& ref)
{
	if (this != &ref)
		this->setType(ref.getType());
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Auf auf!\n";
}
