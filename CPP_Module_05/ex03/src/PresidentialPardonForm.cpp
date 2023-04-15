#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5), _target("")
{
	std::cout << "PresidentialPardonForm: Default constuctor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm: Param constuctor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : AForm(ref.getName(), ref.getGradeSign(), ref.getGradeExe()), _target(ref.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	if (this != &ref)
		*this = ref;
	return *this;
}

const std::string	PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	this->checkExe(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
