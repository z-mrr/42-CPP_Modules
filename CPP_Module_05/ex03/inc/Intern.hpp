#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <AForm.hpp>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
using std::string;
using std::cout;

class AForm;
class Intern
{
public:
	Intern();
	Intern(const Intern&);
	~Intern();

	Intern& operator=(const Intern&);

	class	FormUnknownException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	AForm* PresidentialPardon(const string& target);
	AForm* RobotomyRequest(const string& target);
	AForm* ShrubberyCreation(const string& target);

	AForm*	makeForm(const string& name, const string &target);
};

#endif
