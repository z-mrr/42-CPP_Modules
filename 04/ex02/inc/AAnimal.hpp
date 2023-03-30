#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
public:
	AAnimal();
	AAnimal(const AAnimal &ref);
	virtual ~AAnimal();

	AAnimal&			operator=(const AAnimal& ref);

	std::string		getType() const;
	void			setType(std::string type);
	virtual void	makeSound() const = 0;
	virtual	void	printIdea(int i) const;

protected:
	std::string		_type;
};

#endif
