#include "Form.hpp"

Form::Form() : _gradeSign(150), _gradeExe(150)
{}

Form::Form(const std::string name, int gradeSign) : _name(name), _signed(0), _gradeSign(gradeSign), _gradeExe(150)
{
	std::cout << "Form param constructor called\n";
}

Form::Form(const Form& ref) : _name(ref.getName()), _signed(ref.getSigned()), _gradeSign(ref.getGradeSign()), _gradeExe(ref.getGradeExe())
{
	std::cout << "Form copy constructor called\n";
}

Form::~Form()
{
	std::cout << "Form destructor called\n";
}

const Form&	Form::operator=(const Form& ref)
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

void				Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() < 1)
	{
		b.signForm(*this, "max grade is 1");
		throw Form::GradeTooHighException();
	}
	else if (b.getGrade() <= this->getGradeSign())
	{
		this->_signed = 1;
		b.signForm(*this, "");
	}
	else
	{
		b.signForm(*this, "grade isn't good enough");
		throw Form::GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& o, const Form& ref)
{
	o << ref.getName() << '\n' << ref.getGradeSign() << '\n' << ref.getGradeExe() << '\n' << ref.getSigned() << '\n';
	return o;
}
