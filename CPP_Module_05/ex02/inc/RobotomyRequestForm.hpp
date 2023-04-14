#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	virtual ~RobotomyRequestForm();


	const std::string	getTarget();
	virtual void		execute(Bureaucrat const& executor) const;


private:
	RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

	const std::string	_target;

};

#endif
