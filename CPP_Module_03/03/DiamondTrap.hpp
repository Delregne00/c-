#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap{
	private:
	std::string name;

	public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &otehr);
	~DiamondTrap();

	void	attack(const std::string &target);
	void	whoAmI();

};

std:: ostream& operator<<(std::ostream& os, const ClapTrap& fixed);

#endif
