#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <cstddef>
#include <cstdlib>
#include <iostream>

static void	printTitle(const char *title) {
	std::cout << std::endl << "== " << title << " ==" << std::endl;
}

int	main(void) {
	std::srand(1);

	Intern		intern;
	Bureaucrat	boss("Boss", 1);
	AForm		*form = NULL;

	printTitle("shrubbery creation");
	form = intern.makeForm("shrubbery creation", "garden");
	if (form != NULL) {
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	printTitle("robotomy request");
	form = intern.makeForm("robotomy request", "Bender");
	if (form != NULL) {
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	printTitle("presidential pardon");
	form = intern.makeForm("presidential pardon", "Arthur Dent");
	if (form != NULL) {
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	printTitle("unknown form");
	form = intern.makeForm("coffee request", "Marvin");
	delete form;

	return 0;
}
