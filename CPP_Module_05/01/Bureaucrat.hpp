#ifndef BUREAUCRAT_HPP    
#define BUREAUCRAT_HPP    

#include <iostream>

class Bureaucrat {

private:
    std::string   _name;
    int           _grade;

public:
    class gradeTooHightExemption : public std::exception{
        const char *what() const throw();
    };
    class gradeTooLowExemption : public std::exception{
        const char *what() const throw();
    };
    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();

    std::string getName() const;
    int         getGrade() const;
   
    void gradeTooLow();
    void gradeTooHight();
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& fixed);

#endif