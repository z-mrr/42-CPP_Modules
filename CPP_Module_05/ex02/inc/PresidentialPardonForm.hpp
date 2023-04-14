#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& ref);
	virtual ~PresidentialPardonForm();


	const std::string	getTarget();
	virtual void		execute(Bureaucrat const& executor) const;


private:
	PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);

	const std::string	_target;

};

#endif
