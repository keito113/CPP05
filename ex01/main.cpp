#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

static void	printTitle(const char *title) {
	std::cout << std::endl << "== " << title << " ==" << std::endl;
}

int	main(void) {
	try {
		Bureaucrat	boss("Boss", 10);
		Bureaucrat	intern("Intern", 100);
		Form		permit("Permit", 10, 20);
		Form		secret("Secret", 50, 20);
		Form		direct("Direct", 10, 20);

		printTitle("construction");
		std::cout << boss << std::endl;
		std::cout << permit << std::endl;

		printTitle("signForm success");
		std::cout << permit << std::endl;
		boss.signForm(permit);
		std::cout << permit << std::endl;

		printTitle("signForm failure");
		std::cout << secret << std::endl;
		intern.signForm(secret);
		std::cout << secret << std::endl;

		printTitle("beSigned direct");
		std::cout << direct << std::endl;
		direct.beSigned(boss);
		std::cout << direct << std::endl;
	} catch (std::exception &e) {
		std::cout << "setup error: " << e.what() << std::endl;
	}

	printTitle("invalid form grades");
	try {
		Form	broken("SignHigh", 0, 50);

		std::cout << broken << std::endl;
	} catch (std::exception &e) {
		std::cout << "sign grade 0: " << e.what() << std::endl;
	}

	try {
		Form	broken("SignLow", 151, 50);

		std::cout << broken << std::endl;
	} catch (std::exception &e) {
		std::cout << "sign grade 151: " << e.what() << std::endl;
	}

	try {
		Form	broken("ExecuteHigh", 50, 0);

		std::cout << broken << std::endl;
	} catch (std::exception &e) {
		std::cout << "execute grade 0: " << e.what() << std::endl;
	}

	try {
		Form	broken("ExecuteLow", 50, 151);

		std::cout << broken << std::endl;
	} catch (std::exception &e) {
		std::cout << "execute grade 151: " << e.what() << std::endl;
	}

	return 0;
}
