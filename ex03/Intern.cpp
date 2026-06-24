#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstddef>
#include <iostream>

typedef AForm	*(*FormCreator)(const std::string &target);

struct FormEntry {
	const char	*name;
	FormCreator	create;
};

static AForm	*createShrubbery(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

static AForm	*createRobotomy(const std::string &target) {
	return new RobotomyRequestForm(target);
}

static AForm	*createPresidentialPardon(const std::string &target) {
	return new PresidentialPardonForm(target);
}

Intern::Intern()
{
}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern	&Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm	*Intern::makeForm(const std::string &formName,
			const std::string &target) const {
	static const FormEntry	forms[] = {
		{"shrubbery creation", createShrubbery},
		{"robotomy request", createRobotomy},
		{"presidential pardon", createPresidentialPardon}
	};
	const std::size_t		formCount = sizeof(forms) / sizeof(forms[0]);

	for (std::size_t i = 0; i < formCount; ++i) {
		if (formName == forms[i].name) {
			AForm	*form = forms[i].create(target);

			std::cout << "Intern creates " << forms[i].name << std::endl;
			return form;
		}
	}
	std::cout << "Intern cannot create unknown form: " << formName
		<< std::endl;
	return NULL;
}
