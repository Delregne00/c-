#include "Character.hpp"

Character::Character(): _name("Default"), drop_index(0){
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_dropped[i] = NULL;
}

Character::Character(const std::string &name): _name(name), drop_index(0){
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_dropped[i] = NULL;
}

Character::Character(const Character &other): _name(other._name)
	, drop_index(other.drop_index){
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		if (other._inventory[i])
			_dropped[i] = other._dropped[i]->clone();
		else
			_dropped[i] = NULL;
	}
}

Character	&Character::operator=(const Character &other){
	if (this != &other){
		for (int i = 0; i < 4; i++){
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		_name = other._name;
		drop_index = other.drop_index;
		for (int i = 0; i < 4; i++){
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		for (int i = 0; i < 100; i++)
		{
			if (other._inventory[i])
				_dropped[i] = other._dropped[i]->clone();
			else
				_dropped[i] = NULL;
		}
		}
	return (*this);
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	deletedrop();
}

std::string const	&Character::getName() const{
	return (_name);
}

void	Character::equip(AMateria *m){
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx){
	if (idx >= 0 && idx < 4){
		_dropped[drop_index] = _inventory[idx];
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target){
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}

void	Character::deletedrop(){
	while (drop_index >= 0){
		delete _dropped[drop_index--];
	}
}

