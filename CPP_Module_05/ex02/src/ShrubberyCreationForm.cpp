#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137)
{
	std::cout << "ShrubberyCreationForm: Default constuctor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreation", 145, 137)
{
	std::cout << "ShrubberyCreationForm: Param constuctor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref.getName(), ref.getGradeSign(), ref.getGradeExe())
{
	std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	if (this != &ref)
		*this = ref;
	return *this;
}

const std::string	ShrubberyCreationForm::getTarget()
{
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	this->checkExe(executor);
}
