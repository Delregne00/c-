#ifndef FORM_HPP
#define FORM_HPP

#include <ostream>
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
private:
    const std::string   _name;
    const int           _gradeToSing;
    const int           _gradeToExecute;
    bool                _isSigned;

public:
    Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    Form(const std::string &name, const int gardeToSing, const int gardeToExecute);
    ~Form();

    std::string getName() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;
    bool        getIsSigned() const;

    bool    beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream& os, const Form& fixed);

#endif
