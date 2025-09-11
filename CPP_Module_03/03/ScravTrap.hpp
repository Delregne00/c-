#ifndef SCRAVTRAP_HPP
#define SCRAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScravTrap : virtual public ClapTrap{
public:
	ScravTrap();
	ScravTrap(const std::string &name);
	ScravTrap(const ScravTrap &other);
	ScravTrap &operator=(const ScravTrap &other);
	~ScravTrap();

	void attack(const std::string &target);
	void guardGate();
};

#endif
