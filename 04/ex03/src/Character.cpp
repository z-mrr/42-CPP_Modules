#include "Character.hpp"

Character::Character() : _name("default"), _floor(NULL)
{
	std::cout << "Character default constructor called\n";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string name) : _name(name), _floor(NULL)
{
	std::cout << "Character parameter constructor called\n";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& ref) : _floor(NULL)
{
	std::cout << "Character copy constructor called\n";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = ref;
}

Character::~Character()
{
	std::cout << "Character destructor called\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	clearFloor(this->_floor);
}

void				clearFloor(Floor* floor)
{
	if (floor)
	{
		clearFloor(floor->next);
		delete floor->m;
		delete floor;
	}
}

Character&			Character::operator=(const Character& ref)
{
	if (this != &ref)
	{
		clearFloor(this->_floor);
		this->_name = ref.getName();
		this->_floor = ref._floor;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (ref._inventory[i])
				this->_inventory[i] = ref._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const&	Character::getName() const
{
	return this->_name;
}

void				Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Materia not equipped because type is unknown\n";
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << m->getType() << " materia equipped in slot " << i << " of " << this->getName() << " inventory\n";
			return ;
		}
	}
	std::cout << m->getType() << " materia not equipped because " << this->getName() << " inventory is full\n";
	delete m;
}

void				Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		return ;
	if (this->_inventory[idx])
	{
		std::cout << this->_inventory[idx]->getType() << " materia unequipped from slot " << idx << " of " << this->getName() << " inventory\n";
		if (!this->_floor)
		{
			this->_floor = new Floor;
			this->_floor->m = this->_inventory[idx];
			this->_floor->next = NULL;
		}
		Floor*	tmp = this->_floor;
		while (tmp->next)
			tmp = tmp->next;
		tmp->m = this->_inventory[idx];
		tmp->next = new Floor;
		tmp->next->m = NULL;
		this->_inventory[idx] = NULL;
	}
	std::cout << idx << " slot is empty\n";
}

void				Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
		return ;
	else if (!this->_inventory[idx])
	{
		std::cout << target.getName() << " not attacked because " << idx << " slot if empty\n";
		return ;
	}
	this->_inventory[idx]->use(target);
	std::cout << this->_inventory[idx]->getType() << " materia in slot " << idx << " of " << this->getName() << " inventory used on " << target.getName() << "\n";
}
