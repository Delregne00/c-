#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	try{
		Bureaucrat b1("Andreu", 14);
		ShrubberyCreationForm f1;
		ShrubberyCreationForm f2("Abre");
		RobotomyRequestForm f3;
		PresidentialPardonForm f4;

		std::cout << "F1" << std::endl;
		b1.signForm(f1);
		b1.executeForm(f1);
		std::cout << f1 << std::endl;

		std::cout << "F3" << std::endl;
		b1.signForm(f2);
		b1.executeForm(f2);
		std::cout << f2 << std::endl;

		std::cout << "F3" << std::endl;
		b1.signForm(f3);
		b1.executeForm(f3);
		std::cout << f3 << std::endl;

		std::cout << "F4" << std::endl;
		b1.signForm(f4);
		b1.executeForm(f4);
		std::cout << f4 << std::endl;
	}
	catch (const std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
