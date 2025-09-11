#include "ClapTrap.hpp"
#include "ScravTrap.hpp"

ScravTrap::ScravTrap() : ClapTrap(){
	hit_points = 100;
	energy_points = 50;
	attack_damage= 20;
	std::cout << "ScravTrap default constructor called" << std::endl;
}

ScravTrap::ScravTrap(const std::string &name) : ClapTrap(name){
	hit_points = 100;
	energy_points = 50;
	attack_damage= 20;
	std::cout << "ScravTrap constructor called" << std::endl;
}

ScravTrap::ScravTrap(const ScravTrap &other) : ClapTrap(other){
	std::cout << "SrcavTrap copy constructor called" << std::endl;
}

ScravTrap &ScravTrap::operator=(const ScravTrap &other){
	if (this != &other){
		ClapTrap::operator=(other);
	}
	std::cout << "ScravTrap assignment operator called" << std::endl;
	return (*this);
}

ScravTrap::~ScravTrap(){
	std::cout << "ScarvTrap destructor called" << std::endl;
}

void ScravTrap::attack(const std::string &target){

	if (hit_points <= 0){
		std::cout << "ScravTrap " << name << " is dead, he can't attack" << std::endl;
		return;
	}
	if (energy_points <= 0) {
	std::cout << "ScravTrap " << name << " has no energy" << std::endl;
	return;
	}
	std::cout << "ScravTrap " << name << " attacks " << target
	<< " causing " << attack_damage << " points of damage!" << std::endl;
	energy_points -= 1;
}

void ScravTrap::guardGate(){
	std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}
