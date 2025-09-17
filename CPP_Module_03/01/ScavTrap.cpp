#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name){
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " created "<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other){
	std::cout << "ScavTrap copy constructor called" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << name << " destroyed" <<std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << name <<
	" is now in Gate keeper mode" <<std::endl;
}

void ScavTrap::attack(const std::string &target){
	if (hitPoints <= 0){
		std::cout << "ScavTrap " << name << " is dead, he can't attack" << std::endl;
		return;
	}
	if (energyPoints <= 0) {
	std::cout << "ScavTrap " << name << " has no energy" << std::endl;
	return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target
	<< " causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints -= 1;
}

std:: ostream& operator<<(std::ostream& os, const ScavTrap& fixed){
	os << "Name: " << fixed.getName() << std::endl
	<< "hitPoints: " << fixed.getHitPoints() << std::endl
	<< "energyPoints: " << fixed.getEnergyPoints() << std::endl
	<< "attackDamage: " << fixed.getAttackDamage() << std::endl;

	return os;
}
