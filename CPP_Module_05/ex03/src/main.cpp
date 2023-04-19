#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{/*
		Bureaucrat b("Tone", 1);
		std::cout << b;
		std::cout << '\n';
		std::cout << '\n';

		AForm*	f = new ShrubberyCreationForm("Tone");
		std::cout << *f << '\n';
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
		std::cout << '\n';
		std::cout << '\n';

		f = new RobotomyRequestForm("Tone");
		std::cout << *f << '\n';
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
		std::cout << '\n';
		std::cout << '\n';

		f = new PresidentialPardonForm("Tone");
		std::cout << *f << '\n';
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
*/
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *rrf;
		delete rrf;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	return 0;
}
