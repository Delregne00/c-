#include "includes/headers.h"


int main(){
	IMateriaSource* src = new MateriaSource();
	AMateria *ice =  new Ice();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->equip(ice);
	me->unequip(1);
	delete bob;
	delete me;
	delete src;
	return 0;
}
