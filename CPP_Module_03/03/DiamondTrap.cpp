#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(){
	this->name = "Default";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name),
	FragTrap(name){
	this->name = name;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << name << " created "<<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
	ScavTrap(other), FragTrap(other){
	this->name = other.name;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << name << " is destroyed" << std::endl;
}

void DiamondTrap::attack(const std::string &target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	std::cout << "I am " << this->name <<
	" and my ClapTrap name is " << ClapTrap::name << std::endl;
}



std:: ostream& operator<<(std::ostream& os, const DiamondTrap& fixed){
	os << "Name: " << fixed.getName() << std::endl
	<< "hitPoints: " << fixed.getHitPoints() << std::endl
	<< "energyPoints: " << fixed.getEnergyPoints() << std::endl
	<< "attackDamage: " << fixed.getAttackDamage() << std::endl;

	return os;
}
