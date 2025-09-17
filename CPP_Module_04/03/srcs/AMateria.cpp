#include "AMateria.hpp"

AMateria::AMateria(): type("unknown"){
}

AMateria::AMateria(std::string const &type): type(type){
}

AMateria::AMateria(const AMateria &other): type(other.type){
}

AMateria	&AMateria::operator=(const AMateria &other){
	(void)other;
	return (*this);
}

AMateria::~AMateria(){
}

std::string const	&AMateria::getType() const{
	return (type);
}

void	AMateria::use(ICharacter &target){
	(void)target;
}
