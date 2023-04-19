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

	AForm*	makeForm(const string& name, const string &target);
};

#endif
