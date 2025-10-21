#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other):
    _name(other._name), _grade(other._grade){}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade){
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
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

void Bureaucrat::gradeTooHight(){
    if (_grade -1 < 1){
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::gradeTooLow(){
    if (_grade + 1 > 150){
        throw GradeTooLowException();
    }
    _grade++;
}

void Bureaucrat::signForm(Form &form){
    try{
        form.beSigned(*this);
        std::cout << *this << " signs "
        << form.getName() << " form." <<std::endl;
    }
    catch (const std::exception &e){
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << *this << " couldn't sign " << form.getName()
        << " because " << e.what() << std::endl;
    }

}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& fixed) {
    os << fixed.getName() << " grade: " << fixed.getGrade();
    return os;
}
