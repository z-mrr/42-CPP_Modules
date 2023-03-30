#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("None")
{
	std::cout << "AAnimal constructor called.\n";
}

AAnimal::AAnimal(const AAnimal &ref) : _type(ref.getType())
{
	std::cout << "AAnimal copy constructor called.\n";
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called.\n";
}

AAnimal&		AAnimal::operator=(const AAnimal& ref)
{
	if (this != &ref)
		this->_type = ref.getType();
	return *this;
}

std::string	AAnimal::getType() const
{
	return this->_type;
}

void	AAnimal::setType(std::string type)
{
	this->_type = type;
}

void		AAnimal::makeSound() const
{
	std::cout << "Not sure what sound to make!\n";
}

void	AAnimal::printIdea(int i) const
{
	(void)i;
	std::cout << "I have no idea.\n";
}
