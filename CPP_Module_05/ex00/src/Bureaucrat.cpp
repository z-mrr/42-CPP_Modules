#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Param constructor called\n";
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : _name(ref._name), _grade(ref._grade)
{
	std::cout << "Copy constructor called\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called\n";
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& ref)
{
	if (this != &ref)
		*this = ref;
	return *this;
}

const std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade()
{
	std::cout << "incrementGrade() called\n";
	if (_grade > 1)
		this->_grade -= 1;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "decrementGrade() called\n";
	if (_grade < 150)
		this->_grade += 1;
	else
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat: Grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat: Grade is too low\n";
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& ref)
{
	o << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".\n";
	return o;
}
