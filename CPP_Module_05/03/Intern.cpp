#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other){
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string form, std::string target){
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*creators[3])(const std::string&) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};
	for (int i = 0; i < 3; i++) {
		if (forms[i] == form){
			std::cout << "Intern creates " << form << std::endl;
			return (this->*creators[i])(target);
		}
	}
	std::cerr << "Error: form '" << form << "' does not exist" << std::endl;
	throw FormNotFoundException();
}


