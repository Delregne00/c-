#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);

	void 	execute_action() const;
};

#endif
