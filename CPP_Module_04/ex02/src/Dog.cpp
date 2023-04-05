#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called.\n";
	this->setType("Dog");
	this->_brain = new Brain();
}

Dog::Dog(const Dog &ref) : AAnimal()
{
	std::cout << "Dog copy constructor called.\n";
	this->setType(ref.getType());
	this->_brain = new Brain(*ref._brain);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called.\n";
	delete this->_brain;
}

Dog&	Dog::operator=(const Dog& ref)
{
	if (this != &ref)
	{
		this->setType(ref.getType());
		delete this->_brain;
		this->_brain = new Brain(*ref._brain);
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Auf auf!\n";
}

void	Dog::printIdea(int i) const
{
	std::cout << _brain->ideas[i];
}
