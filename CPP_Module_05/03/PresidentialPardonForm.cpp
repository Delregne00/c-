#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("Presidential pardon form", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("Presidential pardon form", 25, 5), _target(target) {}

void PresidentialPardonForm::execute_action()const{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;

}
