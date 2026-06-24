#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137),
	  _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other),
	  _target(other._target)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::executeAction() const {
	const std::string	fileName = _target + "_shrubbery";
	std::ofstream		file(fileName.c_str());

	if (!file)
		throw std::runtime_error("failed to open shrubbery file");
	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\\\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\\\n";
	file << "\n";
	file << "        &&& &&  & &&\n";
	file << "    && &\\/&\\|& ()|/ @, &&\n";
	file << "    &\\/(/&/&||/& /_/)_&/_&\n";
	file << " &() &\\/&|()|/&\\/ '%\" & ()\n";
	file << " &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	file << "&&   && & &| &| /& & % ()& /&&\n";
	file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
	file << "     &&     \\|||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "             |||\n";
	if (!file)
		throw std::runtime_error("failed to write shrubbery file");
	file.close();
	if (!file)
		throw std::runtime_error("failed to close shrubbery file");
}
