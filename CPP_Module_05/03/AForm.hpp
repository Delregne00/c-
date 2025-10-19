#ifndef AFORM_HPP
#define AFORM_HPP

#include <ostream>
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
private:
    const std::string   _name;
    const int           _gradeToSing;
    const int           _gradeToExecute;
    bool                _isSigned;
    bool                _isExecuted;

public:
    AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    AForm(const std::string &name, const int gardeToSing, const int gardeToExecute);
    virtual ~AForm();

    std::string getName() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;
    bool        getIsSigned() const;
    bool        getIsExecuted() const;

    bool    beSigned(const Bureaucrat &bureaucrat);
    bool    beExecute(const Bureaucrat &bureaucrat);

    virtual void execute_action() const = 0;
};

std::ostream &operator<<(std::ostream& os, const AForm& fixed);

#endif
