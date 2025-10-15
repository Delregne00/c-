#ifndef FORM_HPP
#define FORM_HPP

#include <ostream>

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

    std::string getName();
    int         getGradeToSign();
    int         getGradeToExecute();
    bool        getIsSigned();

    bool    beSigned(const Form &form);
};


#endif