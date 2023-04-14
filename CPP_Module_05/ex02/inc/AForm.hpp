#ifndef AAFORM_HPP
#define AAFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm(const std::string name, int gradeSign, int gradeExe);
	AForm(const AForm& ref);
	virtual ~AForm();

	const std::string	getName() const;
	bool				getSigned() const;
	int					getGradeSign() const;
	int					getGradeExe() const;
	bool				beSigned(Bureaucrat& b);
	virtual void		execute(Bureaucrat const& executor) const = 0;
	void				checkExe(Bureaucrat const& executor) const;

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

	class	FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	AForm();

	AForm& operator=(const AForm& ref);

	const std::string	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExe;
};

std::ostream&			operator<<(std::ostream& o, const AForm& ref);

#endif
