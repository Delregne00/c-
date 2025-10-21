#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include "Exceptions.hpp"
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


#endif
