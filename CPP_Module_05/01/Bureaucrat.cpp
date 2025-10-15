#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other): 
    _name(other._name), _grade(other._grade){}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade){
    if (grade < 1)
        throw gradeTooHightExemption();
    if (grade > 150)
        throw gradeTooLowExemption();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other){
        _name = other._name;
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName()const{
    return _name;
}

int Bureaucrat::getGrade()const{
    return _grade;
}

const char *Bureaucrat::gradeTooHightExemption::what() const throw(){
    return "Grade to hight";
}

const char *Bureaucrat::gradeTooLowExemption::what() const throw(){
    return "Grade to low";
}

void Bureaucrat::gradeTooHight(){
    if (_grade -1 < 1){
        throw gradeTooHightExemption();
    }
    _grade--;
}

void Bureaucrat::gradeTooLow(){
    if (_grade + 1 > 150){
        throw gradeTooLowExemption();
    }
    _grade++;
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& fixed) {
    os << fixed.getName() << " grade: " << fixed.getGrade();
    return os;
} 