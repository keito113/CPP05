#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

static void	section(const char *title) {
	std::cout << std::endl << "== " << title << " ==" << std::endl;
}

static void	createBureaucrat(const char *name, int grade) {
	try {
		Bureaucrat	bureaucrat(name, grade);

		std::cout << "OK   " << bureaucrat << std::endl;
	} catch (const std::exception &e) {
		std::cout << "ERR  " << name << "(" << grade << "): "
			<< e.what() << std::endl;
	}
}

static void	createForm(const char *name, int signGrade, int executeGrade) {
	try {
		Form	form(name, signGrade, executeGrade);

		std::cout << "OK   " << form << std::endl;
	} catch (const std::exception &e) {
		std::cout << "ERR  " << name << "(" << signGrade << ", "
			<< executeGrade << "): " << e.what() << std::endl;
	}
}

static void	signDirectly(Form &form, const Bureaucrat &bureaucrat) {
	std::cout << "before: " << form << std::endl;
	try {
		form.beSigned(bureaucrat);
		std::cout << "signed by " << bureaucrat.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << "caught: " << e.what() << std::endl;
	}
	std::cout << "after:  " << form << std::endl;
}

int	main(void) {
	section("bureaucrat construction");
	createBureaucrat("Top", 1);
	createBureaucrat("Bottom", 150);
	createBureaucrat("TooHigh", 0);
	createBureaucrat("TooLow", 151);

	section("form construction");
	createForm("TopSecret", 1, 1);
	createForm("PublicNotice", 150, 150);
	createForm("BadSignHigh", 0, 50);
	createForm("BadSignLow", 151, 50);
	createForm("BadExecHigh", 50, 0);
	createForm("BadExecLow", 50, 151);

	section("beSigned success and failure");
	Bureaucrat	boss("Boss", 10);
	Bureaucrat	intern("Intern", 100);
	Form		permit("Permit", 10, 20);
	Form		secret("Secret", 50, 20);

	signDirectly(permit, boss);
	signDirectly(secret, intern);

	section("Bureaucrat::signForm");
	Form	contract("Contract", 75, 50);
	Form	order("ExecutiveOrder", 5, 5);

	boss.signForm(contract);
	intern.signForm(order);

	section("already signed still checks authority");
	intern.signForm(contract);

	section("copy and assignment");
	Form	original("OriginalForm", 42, 21);
	Bureaucrat	signer("Signer", 42);
	original.beSigned(signer);
	Form	copied(original);
	Form	left("LeftForm", 100, 100);
	Form	right("RightForm", 10, 10);

	right.beSigned(boss);
	std::cout << "original: " << original << std::endl;
	std::cout << "copy:     " << copied << std::endl;
	std::cout << "before:   " << left << std::endl;
	left = right;
	std::cout << "after:    " << left
		<< " (name and grades stay LeftForm)" << std::endl;
	std::cout << "source:   " << right << std::endl;
	return 0;
}
