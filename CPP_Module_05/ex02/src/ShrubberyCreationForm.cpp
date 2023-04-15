#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), _target("")
{
	std::cout << "ShrubberyCreationForm: Default constuctor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm: Param constuctor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref.getName(), ref.getGradeSign(), ref.getGradeExe()), _target(ref.getTarget())
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

const std::string	ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

const char* ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return "ShrubberyCreationForm: Failed to open file\n";
}

void ShrubberyCreationForm::printTree(std::ofstream& ofs) const
{
	ofs << "       ###             ###              ###          \n";
	ofs << "      #o###           #o###            #o###         \n";
	ofs << "    #####o###        #####o###        #####o###      \n";
	ofs << "   #o#\\#|#/###     #o#\\#|#/###      #o#\\#|#/###   \n";
	ofs << "    ###\\|/#o#       ###\\|/#o#        ###\\|/#o#    \n";
	ofs << "     # }|{  #        # }|{  #         # }|{  #       \n";
	ofs << "       }|{             }|{              }|{          \n";
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	this->checkExe(executor);
	std::string		file = this->getTarget() + "_shrubbery";
	std::ofstream	ofs(file.c_str());
	if (!ofs.is_open())
	{
		throw OpenFileException();
	}
	this->printTree(ofs);
	ofs.close();
}
