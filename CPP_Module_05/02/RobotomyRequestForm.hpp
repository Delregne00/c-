#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);

	bool	randomForm() const;
	void 	execute_action() const;
};

#endif
