#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& ref);
	virtual ~ShrubberyCreationForm();

	class	OpenFileException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	const std::string	getTarget() const;
	virtual void		execute(Bureaucrat const& executor) const;
	void printTree(std::ofstream& ofs) const;

private:
	ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);

	const std::string	_target;
};

#endif
