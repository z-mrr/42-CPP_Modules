#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

struct Floor
{
	AMateria*	m;
	Floor*		next;
};

class Character : public ICharacter
{
public:
	Character();
	Character(const std::string name);
	Character(const Character& ref);
	virtual ~Character();

	Character&					operator=(const Character& ref);

	virtual std::string const&	getName() const;
	virtual void				equip(AMateria* m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& target);

private:
	AMateria*					_inventory[4];
	std::string					_name;
	Floor*						_floor;
};

void							clearFloor(Floor* floor);

#endif
