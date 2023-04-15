#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45), _target("")
{
	std::cout << "RobotomyRequestForm: Default constuctor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequest", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm: Param constuctor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm(ref.getName(), ref.getGradeSign(), ref.getGradeExe()), _target(ref.getTarget())
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

const std::string	RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	this->checkExe(executor);
	std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRR...(illing noise)\n";
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
	{
		std::cout << this->getTarget() << " has been robotomized\n";
	}
	else
	{
		std::cout << "The robotomy on " << this->getTarget() << " failed\n";
	}
}
