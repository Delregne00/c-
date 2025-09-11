#include "ClapTrap.hpp"
#include "ScravTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <cstdio>

void showStats(const ClapTrap &robot)
{
    std::cout << "\033[1;32m" << robot.getName()
              << " | HP: " << robot.getHitPoints()
              << " | EP: " << robot.getEnergyPoints()
              << " | AD: " << robot.getAttackDamage() << "\033[0m" << std::endl;
}

void separator(const std::string &title)
{
    std::cout << "\n\033[1;34m=== " << title << " ===\033[0m" << std::endl;
}

int main()
{
    separator("CONSTRUCTORS TEST");

    // Basic constructors
    ClapTrap robot1("R2D2");
    ClapTrap robot2("C3PO");
    ScravTrap robot3("SCAV01");
    FragTrap robot4("FRAG01");
    DiamondTrap robot5("DIAMOND01");

    separator("COPY CONSTRUCTORS TEST");

    ClapTrap robot1_copy(robot1);
    ScravTrap robot3_copy(robot3);
    FragTrap robot4_copy(robot4);
    DiamondTrap robot5_copy(robot5);

    separator("INITIAL STATS");

    showStats(robot1);
    showStats(robot2);
    showStats(robot3);
    showStats(robot4);
    showStats(robot5);

    separator("DIAMONDTRAP SPECIAL FUNCTION");

    robot5.whoAmI();
    robot5_copy.whoAmI();

    separator("ATTACK TESTS - Different attack methods");

    std::cout << "\n-- ClapTrap attack --" << std::endl;
    robot1.attack("Enemy1");
    showStats(robot1);

    std::cout << "\n-- ScavTrap attack --" << std::endl;
    robot3.attack("Enemy2");
    showStats(robot3);

    std::cout << "\n-- FragTrap attack --" << std::endl;
    robot4.attack("Enemy3");
    showStats(robot4);

    std::cout << "\n-- DiamondTrap attack (should use ScavTrap attack) --" << std::endl;
    robot5.attack("Enemy3");
    showStats(robot5);

    separator("SPECIAL ABILITIES");

    std::cout << "\n-- ScavTrap Guard Gate --" << std::endl;
    robot3.guardGate();

    std::cout << "\n-- FragTrap High Fives --" << std::endl;
    robot4.highFivesGuys();

    std::cout << "\n-- DiamondTrap Who Am I --" << std::endl;
    robot5.whoAmI();

    separator("ENERGY DEPLETION TEST");

    separator("DAMAGE AND REPAIR TESTS");

    std::cout << "\n-- Taking damage --" << std::endl;
    robot1.takeDamage(5);
    showStats(robot1);
    robot3.takeDamage(20);
    showStats(robot3);
    robot5.takeDamage(50);
    showStats(robot5);

    std::cout << "\n-- Repair attempts --" << std::endl;
    robot1.beRepaired(3);
    showStats(robot1);
    robot3.beRepaired(15);
    showStats(robot3);
    robot5.beRepaired(25);
    showStats(robot5);

    separator("ASSIGNMENT OPERATOR TEST");

    std::cout << "\n-- Before assignment --" << std::endl;
    showStats(robot1);
    showStats(robot3);

    robot1 = robot3;  // ClapTrap = ScavTrap (should work through inheritance)

    std::cout << "\n-- After assignment --" << std::endl;
    showStats(robot1);

    std::cout << "\n-- DiamondTrap assignment --" << std::endl;
    DiamondTrap diamond2("DIAMOND02");
    showStats(diamond2);
    diamond2 = robot5;
    showStats(diamond2);
    diamond2.whoAmI();

    separator("POLYMORPHISM TEST");

    ClapTrap* polymorphic1 = new ScravTrap("POLY_SCAV");
    ClapTrap* polymorphic2 = new FragTrap("POLY_FRAG");
    ClapTrap* polymorphic3 = new DiamondTrap("POLY_DIAMOND");

    std::cout << "\n-- Polymorphic attacks --" << std::endl;
    polymorphic1->attack("PolyTarget1");
    polymorphic2->attack("PolyTarget2");
    polymorphic3->attack("PolyTarget3");

    showStats(*polymorphic1);
    showStats(*polymorphic2);
    showStats(*polymorphic3);

    separator("INHERITANCE VERIFICATION");

    std::cout << "\n-- DiamondTrap stats verification --" << std::endl;
    std::cout << "HP should be 100 (FragTrap): " << robot5.getHitPoints() << std::endl;
    std::cout << "EP should be 50 (ScavTrap): " << robot5.getEnergyPoints() << std::endl;
    std::cout << "AD should be 30 (FragTrap): " << robot5.getAttackDamage() << std::endl;

    separator("DEATH TEST");

    std::cout << "\n-- Testing robot death --" << std::endl;
    robot2.takeDamage(100);  // Should kill robot2
    showStats(robot2);
    robot2.attack("DeadTarget");  // Should not work
    robot2.beRepaired(10);       // Should not work

    separator("CLEANUP");

    delete polymorphic1;
    delete polymorphic2;
    delete polymorphic3;

    std::cout << "\n\033[1;33m--- Program ending, destructors will be called ---\033[0m" << std::endl;

    return 0;
}
