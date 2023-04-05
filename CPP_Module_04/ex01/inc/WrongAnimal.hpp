#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &ref);
	~WrongAnimal();

	WrongAnimal&	operator=(const WrongAnimal& ref);

	std::string		getType() const;
	void			setType(std::string type);
	void	makeSound() const;

protected:
	std::string		_type;
};

#endif
