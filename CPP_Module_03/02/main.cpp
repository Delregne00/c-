#include "ClapTrap.hpp"
#include "ScravTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

void showStats(const ClapTrap &robot)
{
	std::cout << "\033[1;32m" << robot.getName()
			  << " | HP: " << robot.getHitPoints()
			  << " | EP: " << robot.getEnergyPoints()
			  << " | AD: " << robot.getAttackDamage() << "\033[0m" << std::endl;
}

int main()
{
	ClapTrap robot1("R2D2");
	ClapTrap robot2("C3PO");
	ClapTrap robot3(robot1);
	ScravTrap robot4("MIN93");
	FragTrap robot5("ISO87");

	std::cout << "\n--- Initial stats ---" << std::endl;
	showStats(robot1);
	showStats(robot2);
	showStats(robot3);
	showStats(robot4);

	std::cout << "\n--- Multiple attacks (testing energy depletion) ---" << std::endl;
	robot1.attack("Enemy1");
	showStats(robot1);
	robot1.attack("Enemy2");
	showStats(robot1);
	robot1.attack("Enemy3");
	showStats(robot1);
	robot1.attack("Enemy4");
	showStats(robot1);
	robot1.attack("Enemy5");
	showStats(robot1);
	robot1.attack("Enemy6");
	showStats(robot1);
	robot1.attack("Enemy7");
	showStats(robot1);
	robot1.attack("Enemy8");
	showStats(robot1);
	robot1.attack("Enemy9");
	showStats(robot1);
	robot1.attack("Enemy10");
	showStats(robot1);
	robot1.attack("Enemy11");
	showStats(robot1);

	std::cout << std::endl << "ScravTrap turn" << std::endl;
	robot4.attack("Enemy10");
	showStats(robot4);
	robot4.attack("Enemy11");
	showStats(robot4);

	std::cout << std::endl << "FragTrap turn" << std::endl;
	robot5.highFivesGuys();
	showStats(robot5);

	std::cout << "\n--- Taking damage ---" << std::endl;
	robot1.takeDamage(5);
	showStats(robot1);
	robot1.takeDamage(3);
	showStats(robot1);

	std::cout << "\n--- Repair attempts ---" << std::endl;
	robot1.beRepaired(4);
	showStats(robot1);
	robot1.beRepaired(2);
	showStats(robot1);

	std::cout << "\n--- Robot2 tests ---" << std::endl;
	robot2.setAttackDamage(25);
	showStats(robot2);
	robot2.attack("Boss");
	showStats(robot2);
	robot2.takeDamage(50);
	showStats(robot2);
	robot2.beRepaired(10);
	showStats(robot2);

	std::cout << "ScravTrap turn" << std::endl;
	robot4.attack("Enemy10");
	showStats(robot4);
	robot4.attack("Enemy11");
	showStats(robot4);

	std::cout << "\n--- Robot3 (copy) tests ---" << std::endl;
	robot3.attack("Target");
	showStats(robot3);
	robot3.takeDamage(8);
	showStats(robot3);
	robot3.beRepaired(5);
	showStats(robot3);

	std::cout << "ScravTrap turn" << std::endl;
	robot4.attack("Enemy10");
	showStats(robot4);
	robot4.attack("Enemy11");
	showStats(robot4);

	std::cout << "\n--- Assignment operator test ---" << std::endl;
	robot1 = robot2;
	showStats(robot1);
	robot1.attack("FinalEnemy");
	showStats(robot1);

	std::cout << "ScravTrap turn" << std::endl;
	robot4.attack("Enemy10");
	showStats(robot4);
	robot4.attack("Enemy11");
	showStats(robot4);
	robot4.guardGate();

	return 0;
}
