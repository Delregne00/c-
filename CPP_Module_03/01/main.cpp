#include "ScavTrap.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int	main(void){

	ClapTrap clap("Clap");
	ScavTrap Robot_one;
	ScavTrap Robot_two("R2D2");
	ScavTrap Robot_three(Robot_two);
	ScavTrap Robot_Four = Robot_one;

	clap.takeDamage(6);
	Robot_one.takeDamage(1);
	Robot_two.takeDamage(5);
	Robot_three.takeDamage(9);

	clap.setAttackDamage(10000000);
	Robot_two.setAttackDamage(3650);

	for (int i = 0; i < 60; i++)
		Robot_two.attack("Boss");

	Robot_three.setAttackDamage(999);
	Robot_three.beRepaired(999);

	Robot_Four.setAttackDamage(25);
	Robot_Four.beRepaired(25);


	std::cout << RED << clap << RESET << std::endl;
	std::cout << GREEN << Robot_one << RESET << std::endl;
	std::cout << YELLOW << Robot_two << RESET <<std::endl;
	std::cout << BLUE <<Robot_three << RESET <<std::endl;
	std::cout << CYAN <<Robot_Four << RESET <<std::endl;

	return(0);
}
