#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal();
	Animal(const Animal &ref);
	virtual ~Animal();

	Animal&			operator=(const Animal& ref);

	std::string		getType() const;
	void			setType(std::string type);
	virtual void	makeSound() const;

protected:
	std::string		type;
};

#endif
