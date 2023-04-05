#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal
{
public:
	Cat();
	Cat(const Cat &ref);
	~Cat();

	Cat&			operator=(const Cat& ref);

	virtual void	makeSound() const;
	virtual	void	printIdea(int i) const;
	void			setIdea(int i, std::string idea);

private:
	Brain*			_brain;
};

#endif
