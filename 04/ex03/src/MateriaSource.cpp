#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	std::cout << "MateriaSource default constructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource& ref)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	*this = ref;
	std::cout << "MateriaSource copy constructor called\n";
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->_materia[i])
			delete this->_materia[i];
	std::cout << "MateriaSource destructor called\n";
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& ref)
{
	if (this != &ref)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			if (ref._materia[i])
				this->_materia[i] = ref._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return *this;
}

void			MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = m;
			std::cout << m->getType() << " added as MateriaSource in slot " << i << "\n";
			return ;
		}
	}
	std::cout << "MateriaSource not added because all slots are full\n";
	delete m;
}

AMateria*		MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
		{
			std::cout << "MateriaSource " << type << " was created\n";
			return this->_materia[i]->clone();
		}
	}
	std::cout << "MateriaSource " << type << " wasn't created because type is unknown\n";
	return NULL;
}
