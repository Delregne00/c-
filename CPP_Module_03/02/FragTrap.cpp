#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	hit_points = 100;
	energy_points = 100;
	attack_damage= 30;
	std::cout << "Fragtrap " << name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name){
	hit_points = 100;
	energy_points = 100;
	attack_damage= 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){
	std::cout << "FragTrap " << name << " copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	if (this != &other){
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << name << " assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << name << " requests a positive high-five!" << std::endl;
}
