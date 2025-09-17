#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
	public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &otehr);
	~ScavTrap();

	void	attack(const std::string &target);
	void	guardGate();

};

std:: ostream& operator<<(std::ostream& os, const ClapTrap& fixed);

#endif
