#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(const std::string name, int gradeSign, int gradeExe);
	Form(const Form& ref);
	~Form();

	const std::string	getName() const;
	bool				getSigned() const;
	int					getGradeSign() const;
	int					getGradeExe() const;
	bool				beSigned(Bureaucrat& b);

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
	Form();

	Form& operator=(const Form& ref);

	const std::string	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExe;
};

std::ostream&			operator<<(std::ostream& o, const Form& ref);

#endif
