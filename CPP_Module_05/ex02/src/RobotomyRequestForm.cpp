#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45)
{
	std::cout << "RobotomyRequestForm: Default constuctor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequest", 72, 45)
{
	std::cout << "RobotomyRequestForm: Param constuctor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm(ref.getName(), ref.getGradeSign(), ref.getGradeExe())
{
	std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	if (this != &ref)
		*this = ref;
	return *this;
}

const std::string	RobotomyRequestForm::getTarget()
{
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	this->checkExe(executor);
}
