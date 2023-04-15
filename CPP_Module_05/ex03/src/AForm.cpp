#include "AForm.hpp"

AForm::AForm() : _name(""), _gradeSign(150), _gradeExe(150)
{
	std::cout << "AForm default constructor called\n";
}

AForm::AForm(const std::string name, int gradeSign, int gradeExe) : _name(name), _signed(0), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
	std::cout << "AForm param constructor called\n";
}

AForm::AForm(const AForm& ref) : _name(ref.getName()), _signed(ref.getSigned()), _gradeSign(ref.getGradeSign()), _gradeExe(ref.getGradeExe())
{
	std::cout << "AForm copy constructor called\n";
}

AForm::~AForm()
{
	std::cout << "AForm destructor called\n";
}

AForm&	AForm::operator=(const AForm& ref)
{
	if (this != &ref)
		*this = ref;
	return *this;
}

const std::string	AForm::getName() const
{
	return this->_name;
}

bool				AForm::getSigned() const
{
	return this->_signed;
}

int			AForm::getGradeSign() const
{
	return this->_gradeSign;
}

int			AForm::getGradeExe() const
{
	return this->_gradeExe;
}

bool	AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (b.getGrade() <= this->getGradeSign())
	{
		this->_signed = 1;
		return 1;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
	return 0;
}

void	AForm::checkExe(Bureaucrat const& executor) const
{
	if (!this->getSigned())
	{
		throw FormNotSignedException();
	}
	else if (executor.getGrade() > this->getGradeExe())
	{
		throw GradeTooLowException();
	}
	else if (executor.getGrade() < 1)
	{
		throw GradeTooHighException();
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm: Grade is too high\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm: Grade is too low\n";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm: Form is not signed\n";
}

std::ostream&	operator<<(std::ostream& o, const AForm& ref)
{
	o << ref.getName() << '\n' << ref.getGradeSign() << '\n' << ref.getGradeExe() << '\n' << ref.getSigned() << '\n';
	return o;
}
