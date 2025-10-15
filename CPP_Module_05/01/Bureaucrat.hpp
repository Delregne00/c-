#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Exceptions.hpp"
#include "Form.hpp"

class Form;

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
    void  signForm(Form &form);
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& fixed);

#endif
