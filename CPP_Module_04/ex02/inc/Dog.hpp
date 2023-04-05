#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
{
public:
	Dog();
	Dog(const Dog &ref);
	~Dog();

	Dog&			operator=(const Dog& ref);

	virtual void	makeSound() const;

	virtual	void	printIdea(int i) const;

private:
	Brain*			_brain;
};

#endif
