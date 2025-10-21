#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));

	Bureaucrat jon("Jon", 1);
	Intern someRandomIntern;
	AForm* rrf = NULL;
	AForm* scf = NULL;
	AForm* ppf = NULL;

	try
	{
		rrf = someRandomIntern.makeForm("roboasdasdastomy request", "Bender");
		jon.signForm(*rrf);
		jon.executeForm(*rrf);
		std::cout << *rrf << std::endl;
	}
	catch (const FormNotFoundException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		jon.signForm(*scf);
		jon.executeForm(*scf);
		std::cout << *scf << std::endl;
	}
	catch (const FormNotFoundException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		jon.signForm(*ppf);
		jon.executeForm(*ppf);
		std::cout << *ppf << std::endl;
	}
	catch (const FormNotFoundException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	delete rrf;
	delete scf;
	delete ppf;

	return 0;
}
