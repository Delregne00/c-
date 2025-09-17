#include "DiamondTrap.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int	main(void){


	DiamondTrap diamond;
	std::cout << std::endl;
	DiamondTrap diamond_1("D1");
	std::cout << std::endl;
	DiamondTrap diamond_2;
	std::cout << std::endl;
	ScavTrap	scav;
	std::cout << std::endl;
	FragTrap	frag;
	std::cout << std::endl;
	ClapTrap	clap;
	std::cout << std::endl;

	diamond_2 = diamond_1;
	std::cout << std::endl;

	diamond_1.takeDamage(150);
	diamond_1.attack("boss");
	std::cout << std::endl;

	diamond.attack("boss");
	std::cout << std::endl;

	diamond.whoAmI();
	diamond_1.whoAmI();
	diamond_2.whoAmI();
	std::cout << std::endl;

	std::cout << BLUE << diamond << RESET <<std::endl;
	std::cout << YELLOW << diamond_1 << RESET <<std::endl;
	std::cout << RED << diamond_2 << RESET <<std::endl;
	std::cout << BLUE << scav << RESET <<std::endl;
	std::cout << MAGENTA << frag << RESET <<std::endl;
	std::cout << CYAN<< clap << RESET <<std::endl;

	return(0);
}
