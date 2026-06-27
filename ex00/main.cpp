#include "Bureaucrat.hpp"

#include <iostream>

static void	printTitle(const char *title) {
	std::cout << std::endl << "== " << title << " ==" << std::endl;
}

int	main(void) {
	printTitle("increment");
	try {
		Bureaucrat	alice("Alice", 2);

		std::cout << alice << std::endl;
		alice.incrementGrade();
		std::cout << "after: " << alice << std::endl;
		alice.incrementGrade();
	} catch (const std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	printTitle("decrement");
	try {
		Bureaucrat	bob("Bob", 149);

		std::cout << bob << std::endl;
		bob.decrementGrade();
		std::cout << "after: " << bob << std::endl;
		bob.decrementGrade();
	} catch (const std::exception &e) {
		std::cout << "error: " << e.what() << std::endl;
	}

	printTitle("invalid constructor");
	try {
		Bureaucrat	tooHigh("TooHigh", 0);

		std::cout << tooHigh << std::endl;
	} catch (const std::exception &e) {
		std::cout << "grade 0: " << e.what() << std::endl;
	}

	try {
		Bureaucrat	tooLow("TooLow", 151);

		std::cout << tooLow << std::endl;
	} catch (const std::exception &e) {
		std::cout << "grade 151: " << e.what() << std::endl;
	}

	return 0;
}
