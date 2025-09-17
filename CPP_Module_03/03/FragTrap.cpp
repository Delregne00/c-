#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name){
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " created "<<std::endl;
}

FragTrap::FragTrap(const FragTrap &other){
	std::cout << "FragTrap copy constructor called" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << name << " destroyed" <<std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap " << name <<
	" requests a positive high five!" <<std::endl;
}

void FragTrap::attack(const std::string &target){
	if (hitPoints <= 0){
		std::cout << "FragTrap " << name << " is dead, he can't attack" << std::endl;
		return;
	}
	if (energyPoints <= 0) {
	std::cout << "FragTrap " << name << " has no energy" << std::endl;
	return;
	}
	std::cout << "FragTrap " << name << " attacks " << target
	<< " causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints -= 1;
}

std:: ostream& operator<<(std::ostream& os, const FragTrap& fixed){
	os << "Name: " << fixed.getName() << std::endl
	<< "hitPoints: " << fixed.getHitPoints() << std::endl
	<< "energyPoints: " << fixed.getEnergyPoints() << std::endl
	<< "attackDamage: " << fixed.getAttackDamage() << std::endl;

	return os;
}
