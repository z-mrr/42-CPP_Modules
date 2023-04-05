#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called.\n";
	this->setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &ref) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called.\n";
	this->setType(ref.getType());
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called.\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& ref)
{
	if (this != &ref)
		this->setType(ref.getType());
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow!\n";
}
