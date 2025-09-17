#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(): name("Default"), hitPoints(10),
	energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap deafult constructor called" << std::endl;
	}

ClapTrap::ClapTrap(const ClapTrap &other){
	std::cout << "ClapTrap copy constructor called" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : hitPoints(10),
	energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " created" << std::endl;
	this->name = name;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
		std::cout << "ClapTrap " << name <<
		" copy asssignament operator called" << std::endl;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void ClapTrap::setAttackDamage(unsigned int amount){
	attackDamage = amount;
}

void ClapTrap::attack(const std::string &target){

	if (hitPoints <= 0){
		std::cout << "ClapTrap " << name << " is dead, he can't attack" << std::endl;
		return;
	}
	if (energyPoints <= 0) {
	std::cout << "ClapTrap " << name << " has no energy" << std::endl;
	return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target
	<< " causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (!hitPoints){
		std::cout << "ClapTrap " << name << " is dead , he can't take damage" << std::endl;
	}
	if (amount != 0){
		std::cout << "ClapTrap " << name << " takes " << amount << " of damge" << std::endl;
		hitPoints -= amount;
	}
	else
		std::cout << "ClapTrap " << name << " no damage taken" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!hitPoints){
		std::cout << "ClapTrap " << name << " is dead, can't be repaired" << std::endl;
		return;
	}
	if (energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " has no energy" << std::endl;
		return;
	}
	if (!amount){
		std::cout << "ClapTrap " << name << " healing failed" << std::endl;
		return;
	}
	else{
		std::cout << "ClapTrap " << name << " recovers " << amount << " health points" << std::endl;
		hitPoints += amount;
		energyPoints -= 1;
	}
}
std::string ClapTrap::getName()const{
	return(name);
}

int ClapTrap::getHitPoints()const{
	return(hitPoints);
}

int ClapTrap::getEnergyPoints()const{
	return(energyPoints);
}

int ClapTrap::getAttackDamage()const{
	return(attackDamage);
}

std:: ostream& operator<<(std::ostream& os, const ClapTrap& fixed){
	os << "Name: " << fixed.getName() << std::endl
	<< "hitPoints: " << fixed.getHitPoints() << std::endl
	<< "energyPoints: " << fixed.getEnergyPoints() << std::endl
	<< "attackDamage: " << fixed.getAttackDamage() << std::endl;

	return os;
}
