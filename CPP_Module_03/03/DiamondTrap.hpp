#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScravTrap.hpp"
#include <iostream>

class DiamondTrap: public FragTrap, public ScravTrap {
	private:
		std::string name;

	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap();
		using ScravTrap::attack;

		void whoAmI();
};

#endif
