#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called.\n";
	this->setType("Cat");
	this->_brain = new Brain();
}

Cat::Cat(const Cat &ref) : Animal()
{
	std::cout << "Cat copy constructor called.\n";
	this->setType(ref.getType());
	this->_brain = new Brain(*ref._brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called.\n";
	delete this->_brain;
}

Cat&	Cat::operator=(const Cat& ref)
{
	if (this != &ref)
	{
		this->setType(ref.getType());
		delete this->_brain;
		this->_brain = new Brain(*ref._brain);
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miau!\n";
}

void	Cat::printIdea(int i) const
{
	std::cout << _brain->ideas[i];
}

void	Cat::setIdea(int i, std::string idea)
{
	_brain->ideas[i] = idea;
}
