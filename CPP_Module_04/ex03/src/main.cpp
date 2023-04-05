#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* oldsrc = new MateriaSource();
	AMateria* test = NULL;
	oldsrc->learnMateria(test);
	oldsrc->learnMateria(new Ice());
	oldsrc->learnMateria(new Cure());
	oldsrc->learnMateria(new Ice());
	oldsrc->learnMateria(new Cure());
	oldsrc->learnMateria(new Cure());
	IMateriaSource* src = new MateriaSource(*(MateriaSource*)oldsrc);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("death spike");//unknown
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");//full
	me->equip(tmp);
	me->unequip(0);//doesnt delete
	ICharacter* bob = new Character("bob");
	ICharacter* tony = new Character(*(Character*)me);
	tony->use(0, *bob);//unequiped
	tony->use(1, *bob);
	tony->use(2, *bob);
	tony->use(3, *bob);
	tony->use(4, *bob);//ignored
	delete bob;
	delete tony;
	delete me;
	delete src;
	delete oldsrc;
	return 0;
}
