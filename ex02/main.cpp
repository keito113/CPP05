#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

static void	printTitle(const std::string &title) {
	std::cout << std::endl << "== " << title << " ==" << std::endl;
}

static void	testGradeBoundaries() {
	printTitle("grade boundaries");
	try {
		Bureaucrat top("Top", 1);
		Bureaucrat bottom("Bottom", 150);

		std::cout << top << std::endl;
		std::cout << bottom << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Valid boundary construction failed: " << e.what()
			<< "." << std::endl;
	}
	try {
		Bureaucrat tooHigh("TooHigh", 0);
		std::cout << tooHigh << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Bureaucrat grade 0 failed: " << e.what() << "."
			<< std::endl;
	}
	try {
		Bureaucrat tooLow("TooLow", 151);
		std::cout << tooLow << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Bureaucrat grade 151 failed: " << e.what() << "."
			<< std::endl;
	}
	try {
		ShrubberyCreationForm shrubbery("boundary");
		std::cout << shrubbery << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Form construction failed: " << e.what() << "."
			<< std::endl;
	}
}

static void	testShrubbery() {
	printTitle("shrubbery");
	Bureaucrat				signer("Signer137", 137);
	Bureaucrat				lowSigner("LowSigner146", 146);
	Bureaucrat				lowExecutor("LowExecutor138", 138);
	ShrubberyCreationForm	form("home");

	lowExecutor.executeForm(form);
	lowSigner.signForm(form);
	signer.signForm(form);
	lowExecutor.executeForm(form);
	signer.executeForm(form);
}

static void	testRobotomy() {
	printTitle("robotomy");
	Bureaucrat			robotomist("Robotomist45", 45);
	RobotomyRequestForm	form("Bender");

	robotomist.signForm(form);
	for (int i = 0; i < 6; ++i)
		robotomist.executeForm(form);
}

static void	testPardon() {
	printTitle("presidential pardon");
	Bureaucrat					president("President5", 5);
	Bureaucrat					minister("Minister25", 25);
	PresidentialPardonForm		form("Arthur Dent");

	minister.signForm(form);
	minister.executeForm(form);
	president.executeForm(form);
}

int	main() {
	std::srand(std::time(NULL));
	testGradeBoundaries();
	testShrubbery();
	testRobotomy();
	testPardon();
	return 0;
}
