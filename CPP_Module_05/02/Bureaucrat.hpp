#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Exceptions.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat {

private:
    std::string   _name;
    int           _grade;

public:

    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();

    std::string getName() const;
    int         getGrade() const;

    void gradeTooLow();
    void gradeTooHight();
    void  signForm(AForm &Form) const;
    void  executeForm(AForm &Form) const;
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& fixed);

#endif
