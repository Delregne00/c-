#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Grade is too high!";
    }
};

class GradeTooLowException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Grade is too low!";
    }
};

class NotSignedException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "The form it's not signed";
    }
};

class FormNotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Not found this form!";
    }
};

#endif
