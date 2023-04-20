#include "Form.hpp"

Form::Form() : _name(""), _signed(0), _gradeSign(150), _gradeExe(150)
{
	std::cout << "Form default constructor called\n";
}

Form::Form(const std::string name, int gradeSign, int gradeExe) : _name(name), _signed(0), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
	std::cout << "Form param constructor called\n";
	if (this->getGradeSign() > 150 || this->getGradeExe() > 150)
		throw Form::GradeTooLowException();
	else if (this->getGradeSign() < 1 || this->getGradeExe() < 1)
		throw Form::GradeTooHighException();

}

Form::Form(const Form& ref) : _name(ref.getName()), _signed(ref.getSigned()), _gradeSign(ref.getGradeSign()), _gradeExe(ref.getGradeExe())
{
	std::cout << "Form copy constructor called\n";
}

Form::~Form()
{
	std::cout << "Form destructor called\n";
}

Form&	Form::operator=(const Form& ref)
{
	if (this != &ref)
		*this = ref;
	return *this;
}

const std::string	Form::getName() const
{
	return this->_name;
}

bool				Form::getSigned() const
{
	return this->_signed;
}

int			Form::getGradeSign() const
{
	return this->_gradeSign;
}

int			Form::getGradeExe() const
{
	return this->_gradeExe;
}

bool	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (b.getGrade() <= this->getGradeSign())
	{
		this->_signed = 1;
		return 1;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
	return 0;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade is too high\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade is too low\n";
}

std::ostream&	operator<<(std::ostream& o, const Form& ref)
{
	o << ref.getName() << '\n' << ref.getGradeSign() << '\n' << ref.getGradeExe() << '\n' << ref.getSigned() << '\n';
	return o;
}
