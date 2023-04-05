#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& ref);
	~WrongCat();

	WrongCat&		operator=(const WrongCat& ref);

	void	makeSound() const;
};

#endif
