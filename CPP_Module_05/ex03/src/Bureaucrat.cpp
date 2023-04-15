#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat param constructor called\n";
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : _name(ref._name), _grade(ref._grade)
{
	std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& ref)
{
	this->_grade = ref._grade;
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
	if (this->getGrade() > 1)
		this->_grade -= 1;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "decrementGrade() called\n";
	if (this->getGrade() < 150)
		this->_grade += 1;
	else
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		if (form.getSigned())
			std::cout << this->getName() << " couldn't sign " << form.getName() << " because it was already signed\n";
		else if (form.beSigned(*this))
			std::cout << this->getName() << " signed " << form.getName() << '\n';
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << e.what();
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because grade is too high\n";

	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << e.what();
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because grade is too low\n";
	}
}

void	Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		std::cout << this->getName() << " executed " << form.getName() << '\n';
		form.execute(*this);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
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
