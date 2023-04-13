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
	void				signForm(const Form& form, std::string reason) const;

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Bureaucrat: Grade is too high\n";
		}
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Bureaucrat: Grade is too low\n";
		}
	};

private:
	Bureaucrat();

	const std::string	_name;
	int					_grade;
};

std::ostream&			operator<<(std::ostream& o, const Bureaucrat& ref);

#endif
