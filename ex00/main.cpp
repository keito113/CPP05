#include "Bureaucrat.hpp"

#include <iostream>

static void	section(const char *title) {
	std::cout << std::endl << "== " << title << " ==" << std::endl;
}

static void	createBureaucrat(const char *name, int grade) {
	try {
		Bureaucrat	bureaucrat(name, grade);

		std::cout << "OK   " << bureaucrat << std::endl;
	} catch (std::exception &e) {
		std::cout << "ERR  " << name << "(" << grade << "): "
			<< e.what() << std::endl;
	}
}

static void	increment(Bureaucrat &bureaucrat) {
	std::cout << "before: " << bureaucrat << std::endl;
	try {
		bureaucrat.incrementGrade();
		std::cout << "after:  " << bureaucrat << std::endl;
	} catch (std::exception &e) {
		std::cout << "caught: " << e.what() << std::endl;
		std::cout << "after:  " << bureaucrat << std::endl;
	}
}

static void	decrement(Bureaucrat &bureaucrat) {
	std::cout << "before: " << bureaucrat << std::endl;
	try {
		bureaucrat.decrementGrade();
		std::cout << "after:  " << bureaucrat << std::endl;
	} catch (std::exception &e) {
		std::cout << "caught: " << e.what() << std::endl;
		std::cout << "after:  " << bureaucrat << std::endl;
	}
}

int	main(void) {
	section("construction");
	createBureaucrat("Top", 1);
	createBureaucrat("Bottom", 150);
	createBureaucrat("TooHigh", 0);
	createBureaucrat("TooLow", 151);

	section("grade changes");
	Bureaucrat	bob("Bob", 3);
	Bureaucrat	john("John", 149);
	increment(bob);
	decrement(john);

	section("boundary safety");
	Bureaucrat	highest("Highest", 1);
	Bureaucrat	lowest("Lowest", 150);
	increment(highest);
	decrement(lowest);

	section("copy and assignment");
	Bureaucrat	original("Original", 42);
	Bureaucrat	copied(original);
	Bureaucrat	left("Left", 100);
	Bureaucrat	right("Right", 10);

	std::cout << "original: " << original << std::endl;
	std::cout << "copy:     " << copied << std::endl;
	std::cout << "before:   " << left << std::endl;
	left = right;
	std::cout << "after:    " << left << " (name stays Left)" << std::endl;
	std::cout << "source:   " << right << std::endl;
	return 0;
}
