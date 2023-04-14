#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& ref);
	virtual ~ShrubberyCreationForm();

	const std::string	getTarget();
	virtual void		execute(Bureaucrat const& executor) const;


private:
	ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);

	const std::string	_target;

};

#endif
