#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called\n";
}

Ice::Ice(const Ice& ref) : AMateria(ref.getType())
{
	std::cout << "Ice copy constructor called\n";
	*this = ref;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called\n";
}

Ice&	Ice::operator=(const Ice& ref)
{
	if (this != &ref)
		*this = ref;
	return *this;
}

AMateria*	Ice::clone() const
{
	std::cout << "New Ice cloned\n";
	return new Ice();
}

void	Ice::use(ICharacter &target)
{
		std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
