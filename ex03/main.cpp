#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

static void	printTitle(const std::string &title) {
	std::cout << std::endl << "== " << title << " ==" << std::endl;
}

static void	createSignExecute(const Intern &intern,
				const Bureaucrat &bureaucrat,
				const std::string &formName,
				const std::string &target) {
	AForm	*form = intern.makeForm(formName, target);

	if (form == NULL)
		return;
	try {
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
	} catch (...) {
		delete form;
		throw;
	}
	delete form;
}

int	main() {
	std::srand(std::time(NULL));
	Intern		someRandomIntern;
	Bureaucrat	executor("Executor", 1);

	printTitle("known forms");
	createSignExecute(someRandomIntern, executor,
		"shrubbery creation", "home");
	createSignExecute(someRandomIntern, executor,
		"robotomy request", "Bender");
	createSignExecute(someRandomIntern, executor,
		"presidential pardon", "Arthur Dent");

	printTitle("unknown form");
	createSignExecute(someRandomIntern, executor,
		"coffee request", "Marvin");
	return 0;
}
