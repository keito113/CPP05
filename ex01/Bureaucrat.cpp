#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

static const int	HIGHEST_GRADE = 1;
static const int	LOWEST_GRADE = 150;

static int	validateGrade(int grade) {
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	return grade;
}

Bureaucrat::Bureaucrat()
	: _name("default"),
	  _grade(LOWEST_GRADE)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name),
	  _grade(validateGrade(grade))
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name),
	  _grade(other._grade)
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string	&Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::incrementGrade() {
	if (_grade == HIGHEST_GRADE)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrementGrade() {
	if (_grade == LOWEST_GRADE)
		throw GradeTooLowException();
	++_grade;
}

void	Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "bureaucrat grade is too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "bureaucrat grade is too low";
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << ".";
	return out;
}
