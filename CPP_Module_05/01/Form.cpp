#include "Form.hpp"

Form::Form(): _name("default"), _gradeToSing(150), _gradeToExecute(150), _isSigned(false){}

Form::Form(const std::string &name, const int gradeToSing, const int gradeToExecute):
	_name(name),_gradeToSing(gradeToSing), _gradeToExecute(gradeToExecute), _isSigned(false){
		if (_gradeToSing < 1 || _gradeToExecute < 1)
			throw GradeTooHighException();
		if (_gradeToSing > 150 || _gradeToExecute > 150)
			throw GradeTooLowException();
}

Form::Form(const Form &other): _name(other._name), _gradeToSing(other._gradeToSing),
	_gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned) {
		if (_gradeToSing < 1 || _gradeToExecute < 1)
			throw GradeTooHighException();
		if (_gradeToSing > 150 || _gradeToExecute < 150)
			throw GradeTooLowException();
}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const{
	return _name;
}

int Form::getGradeToSign() const{
	return _gradeToSing;
}

int Form::getGradeToExecute() const{
	return _gradeToExecute;
}

bool Form::getIsSigned() const{
	return _isSigned;
}

bool    Form::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() <= _gradeToSing){
		this->_isSigned = true;
		return true;
	}
	else
		throw GradeTooLowException();

}

std::ostream &operator<<(std::ostream& os, const Form& form) {
	os << "Form: " << form.getName() << std::endl
	   << "Grade to sign: " << form.getGradeToSign() << std::endl
	   << "Grade to execute: " << form.getGradeToExecute() << std::endl
	   << "from staus: " << (form.getIsSigned() ? "Is signed": "it's not signed");

	return os;
}
