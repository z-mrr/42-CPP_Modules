#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called.\n";
	this->setType("Cat");
}

Cat::Cat(const Cat &ref) : Animal()
{
	std::cout << "Cat copy constructor called.\n";
	this->setType(ref.getType());
}

Cat::~Cat()
{
	std::cout << "Cat destructor called.\n";
}

Cat&	Cat::operator=(const Cat& ref)
{
	if (this != &ref)
		this->setType(ref.getType());
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miau!\n";
}
