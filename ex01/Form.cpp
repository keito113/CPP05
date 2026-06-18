#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <ostream>

static const int	HIGHEST_GRADE = 1;
static const int	LOWEST_GRADE = 150;

static int	validateGrade(int grade) {
	if (grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	return grade;
}

Form::Form()
	: _name("default"),
	  _isSigned(false),
	  _signGrade(LOWEST_GRADE),
	  _executeGrade(LOWEST_GRADE)
{
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
	: _name(name),
	  _isSigned(false),
	  _signGrade(validateGrade(signGrade)),
	  _executeGrade(validateGrade(executeGrade))
{
}

Form::Form(const Form &other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _signGrade(other._signGrade),
	  _executeGrade(other._executeGrade)
{
}

Form	&Form::operator=(const Form &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{
}

const std::string	&Form::getName() const {
	return _name;
}

bool	Form::getIsSigned() const {
	return _isSigned;
}

int	Form::getSignGrade() const {
	return _signGrade;
}

int	Form::getExecuteGrade() const {
	return _executeGrade;
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "form grade is too high";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "form grade is too low";
}

std::ostream	&operator<<(std::ostream &out, const Form &form) {
	out << "Form " << form.getName() << ", signed: ";
	if (form.getIsSigned())
		out << "yes";
	else
		out << "no";
	out << ", sign grade " << form.getSignGrade()
		<< ", execute grade " << form.getExecuteGrade() << ".";
	return out;
}
