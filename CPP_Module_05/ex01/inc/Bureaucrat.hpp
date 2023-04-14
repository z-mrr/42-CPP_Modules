#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& ref);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& ref);

	const std::string	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form& form);

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	Bureaucrat();

	const std::string	_name;
	int					_grade;
};

std::ostream&			operator<<(std::ostream& o, const Bureaucrat& ref);

#endif
