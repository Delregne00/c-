#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
	private:
		std::string	name;
		int	hit_points;
		int	energy_points;
		int	attack_damage;

	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		void	setAttackDamage(unsigned int amount);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string 	getName() const;
		int 			getHitPoints() const;
		int 			getEnergyPoints() const;
		int 			getAttackDamage() const;
};

#endif

