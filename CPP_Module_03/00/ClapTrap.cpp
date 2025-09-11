#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(): name(""), hit_points(10),
	energy_points(10), attack_damage(0) {
	}

ClapTrap::ClapTrap(const ClapTrap &other){
	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
}

ClapTrap::ClapTrap(const std::string &name) : hit_points(10),
	energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap " << name << " is born" << std::endl;
	this->name = name;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << name << " is dead" << std::endl;
}

void ClapTrap::setAttackDamage(unsigned int amount){
	attack_damage = amount;
}

void ClapTrap::attack(const std::string &target){

	if (hit_points <= 0){
		std::cout << "ClapTrap " << name << " is dead, he can't attack" << std::endl;
		return;
	}
	if (energy_points <= 0) {
	std::cout << "ClapTrap " << name << " has no energy" << std::endl;
	return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target
	<< " causing " << attack_damage << " points of damage!" << std::endl;
	energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (!hit_points){
		std::cout << "ClapTrap " << name << " is dead , he can't take damge" << std::endl;
	}
	if (amount != 0){
		std::cout << "ClapTrap " << name << " takes " << amount << " of damge" << std::endl;
		hit_points -= amount;
	}
	else
		std::cout << "ClapTrap " << name << " no damage taken" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!hit_points){
		std::cout << "ClapTrap " << name << " is dead, can't be repaired" << std::endl;
		return;
	}
	if (energy_points <= 0) {
		std::cout << "ClapTrap " << name << " has no energy" << std::endl;
		return;
	}
	if (!amount){
		std::cout << "ClapTrap " << name << " healing failed" << std::endl;
		return;
	}
	else{
		std::cout << "ClapTrap " << name << " recovers " << amount << " health points" << std::endl;
		hit_points += amount;
		energy_points -= 1;
	}
}
std::string ClapTrap::getName()const{
	return(name);
}

int ClapTrap::getHitPoints()const{
	return(hit_points);
}

int ClapTrap::getEnergyPoints()const{
	return(energy_points);
}

int ClapTrap::getAttackDamage()const{
	return(attack_damage);
}
