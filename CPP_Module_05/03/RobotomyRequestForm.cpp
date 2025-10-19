#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	AForm("Robotom request form", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("Robotom request form", 72, 45), _target(target) {}

bool RobotomyRequestForm::randomForm() const{
    return rand() % 2 == 1;
}

void RobotomyRequestForm::execute_action()const{
    std::cout << "Makes some drilling noises" << std::endl;
    if (randomForm())
        std::cout << _target <<" has been robotomized" << std::endl;
    else
        std::cout << _target <<" robotomy failed." << std::endl;
}

