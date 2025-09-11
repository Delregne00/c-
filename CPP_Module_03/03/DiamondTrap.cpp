#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScravTrap()
{
	name = "default";
	hit_points = FragTrap::hit_points;
	energy_points = ScravTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"),
	FragTrap(name), ScravTrap(name){
	this->name = name;
	hit_points = FragTrap::hit_points;
	energy_points = ScravTrap::energy_points;
	attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
	FragTrap(other), ScravTrap(other){
	name =other.name;
	std::cout << "DiamondTrap " << name << " copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator =(const DiamondTrap &other){
	if (this != &other){
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScravTrap::operator=(other);
		name = other.name;
	}
	std::cout << "DiamondTrap " << name << " assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

