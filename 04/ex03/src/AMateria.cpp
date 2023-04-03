#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
	std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << "AMateria parameter constructor called\n";
}

AMateria::AMateria(const AMateria& ref)
{
	std::cout << "AMateria copy constructor called\n";
	*this = ref;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called\n";
}

AMateria&	AMateria::operator=(const AMateria& ref)
{
	if (this != &ref)
		this->_type = ref.getType();
	return *this;
}

const std::string&	AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter &target)
{
		std::cout << "* nothing happens to " << target.getName() << " *\n";
}
