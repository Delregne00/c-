#include "Form.hpp"

Form::Form(): _name("Default"), _gradeToSing(150),
     _gradeToExecute(150), _isSigned(false) {}

Form::Form(const Form &other):  _name(other._name), _gradeToSing(other._gradeToSing),
     _gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned) {}

