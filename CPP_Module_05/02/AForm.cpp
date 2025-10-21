#include "AForm.hpp"

AForm::AForm(): _name("default"), _gradeToSing(150), _gradeToExecute(150),
	 _isSigned(false), _isExecuted(false){}

AForm::AForm(const std::string &name, const int gradeToSing, const int gradeToExecute):
	_name(name),_gradeToSing(gradeToSing), _gradeToExecute(gradeToExecute),
	_isSigned(false), _isExecuted(false){
		if (_gradeToSing < 1 || _gradeToExecute < 1)
			throw GradeTooHighException();
		if (_gradeToSing > 150 || _gradeToExecute > 150)
			throw GradeTooLowException();
}

AForm::AForm(const AForm &other): _name(other._name), _gradeToSing(other._gradeToSing),
	_gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned),
	 _isExecuted(other._isExecuted){}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other){
		_isSigned = other._isSigned;
		_isExecuted = other._isExecuted;
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const{
	return _name;
}

int AForm::getGradeToSign() const{
	return _gradeToSing;
}

int AForm::getGradeToExecute() const{
	return _gradeToExecute;
}

bool AForm::getIsSigned() const{
	return _isSigned;
}

bool AForm::getIsExecuted() const{
	return _isExecuted;
}

bool    AForm::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() <= _gradeToSing){
		this->_isSigned = true;
		return true;
	}
	else
		throw GradeTooLowException();

}

bool    AForm::beExecute(const Bureaucrat &bureaucrat){
	if (!getIsSigned())
		throw	NotSignedException();
	if (bureaucrat.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	this->_isExecuted = true;
	return true;

}

std::ostream &operator<<(std::ostream& os, const AForm& AForm) {
	os << "AForm: " << AForm.getName() << std::endl
	   << "Grade to sign: " << AForm.getGradeToSign() << std::endl
	   << "Grade to execute: " << AForm.getGradeToExecute() << std::endl
	   << "from staus: " << (AForm.getIsSigned() ? "Is signed": "it's not signed") << std::endl
	   << "from execute: " << (AForm.getIsExecuted() ? "Is executed": "it's not excuted");

	return os;
}
