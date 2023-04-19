#include "Intern.hpp"

Intern::Intern()
{
	cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern& ref)
{
	cout << "Intern copy constructor called\n";
	*this = ref;
}

Intern::~Intern()
{
	cout << "Intern destructor called\n";
}

Intern& Intern::operator=(const Intern& ref)
{
	(void)ref;
	return *this;
}

const char* Intern::FormUnknownException::what() const throw()
{
	return "Form name unknown, try: \"presidential pardon\", \"robotomy request\", \"shrubbery creation\"\n";
}

AForm*	Intern::makeForm(const string& name, const string& target)
{
	string	form[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (form[i] == name)
		{
			cout << "Intern creates " << form[i] << "\n";
			switch (i)
			{
				case 0:
					return new PresidentialPardonForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new ShrubberyCreationForm(target);
			}
		}
	}
	throw FormUnknownException();
}
