#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iosfwd>
#include <string>

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_executeGrade;

	virtual void	executeAction() const = 0;

protected:
	AForm();
	AForm(const std::string &name, int signGrade, int executeGrade);

public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};

	AForm(const AForm &other);
	AForm	&operator=(const AForm &other);
	virtual ~AForm();

	const std::string	&getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;

	void	beSigned(const Bureaucrat &bureaucrat);
	void	execute(const Bureaucrat &executor) const;
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);

#endif
