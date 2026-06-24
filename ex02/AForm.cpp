#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

static const int	HIGHEST_GRADE = 1;
static const int	LOWEST_GRADE = 150;

static int	validateGrade(int grade) {
	if (grade < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
	return grade;
}

AForm::AForm()
	: _name("default"),
	  _isSigned(false),
	  _signGrade(LOWEST_GRADE),
	  _executeGrade(LOWEST_GRADE)
{
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: _name(name),
	  _isSigned(false),
	  _signGrade(validateGrade(signGrade)),
	  _executeGrade(validateGrade(executeGrade))
{
}

AForm::AForm(const AForm &other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _signGrade(other._signGrade),
	  _executeGrade(other._executeGrade)
{
}

AForm	&AForm::operator=(const AForm &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{
}

const std::string	&AForm::getName() const {
	return _name;
}

bool	AForm::getIsSigned() const {
	return _isSigned;
}

int	AForm::getSignGrade() const {
	return _signGrade;
}

int	AForm::getExecuteGrade() const {
	return _executeGrade;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(const Bureaucrat &executor) const {
	if (!_isSigned)
		throw NotSignedException();
	if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
	executeAction();
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return "form grade is too high";
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return "form grade is too low";
}

const char	*AForm::NotSignedException::what() const throw() {
	return "form is not signed";
}

std::ostream	&operator<<(std::ostream &out, const AForm &form) {
	out << form.getName() << ", signed: ";
	if (form.getIsSigned())
		out << "yes";
	else
		out << "no";
	out << ", sign grade " << form.getSignGrade()
		<< ", execute grade " << form.getExecuteGrade() << ".";
	return out;
}
