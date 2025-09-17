#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap{
	public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &otehr);
	~FragTrap();

	void	attack(const std::string &target);
	void highFivesGuys(void);

};

std:: ostream& operator<<(std::ostream& os, const FragTrap& fixed);

#endif
