#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &ref);
	virtual ~Dog();

	Dog&			operator=(const Dog& ref);

	virtual void	makeSound() const;

	virtual	void	printIdea(int i) const;

private:
	Brain*			_brain;
};

#endif
