#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern  &otehr);
	~Intern();

	AForm *createShrubbery(const std::string &target);
	AForm *createRobotomy(const std::string &target);
	AForm *createPresidential(const std::string &target);

	AForm	*makeForm(const std::string form, std::string target);

};

#endif
