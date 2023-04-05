#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& ref);
	virtual ~MateriaSource();

	MateriaSource&		operator=(const MateriaSource& ref);

	virtual void		learnMateria(AMateria*);
	virtual AMateria*	createMateria(std::string const& type);

private:
	AMateria*			_materia[4];
};

#endif
