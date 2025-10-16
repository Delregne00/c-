#ifndef SHRUBBERYCRETIONFORM_HPP
#define SHRUBBERYCRETIONFORM_HPP

#include <fstream>
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);

	void 	execute_action() const;
};

#endif
