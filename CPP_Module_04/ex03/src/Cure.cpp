#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called\n";
}

Cure::Cure(const Cure& ref) : AMateria(ref.getType())
{
	std::cout << "Cure copy constructor called\n";
	*this = ref;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called\n";
}

Cure&	Cure::operator=(const Cure& ref)
{
	if (this != &ref)
		*this = ref;
	return *this;
}

AMateria*	Cure::clone() const
{
	std::cout << "New cure cloned\n";
	return new Cure();
}

void	Cure::use(ICharacter &target)
{
		std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

