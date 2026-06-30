#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <iostream>

static void	printTitle(const char *title) {
	std::cout << std::endl << "== " << title << " ==" << std::endl;
}

int	main(void) {
	std::srand(1);

	Bureaucrat				boss("Boss", 1);
	Bureaucrat				trainee("Trainee", 150);
	ShrubberyCreationForm	shrubbery("garden");
	RobotomyRequestForm		robotomy("Bender");
	PresidentialPardonForm	pardon("Arthur Dent");

	printTitle("form requirements");
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;

	printTitle("shrubbery");
	trainee.executeForm(shrubbery);
	boss.signForm(shrubbery);
	boss.executeForm(shrubbery);

	printTitle("robotomy");
	boss.signForm(robotomy);
	boss.executeForm(robotomy);

	printTitle("pardon");
	trainee.signForm(pardon);
	boss.signForm(pardon);
	trainee.executeForm(pardon);
	boss.executeForm(pardon);

	return 0;
}
