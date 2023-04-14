#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try
	{
		Bureaucrat b("Tone", 5);
		std::cout << b;

		AForm	*f = new ShrubberyCreationForm("asd");
		std::cout << f;
		b.signForm(*f);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}

	return 0;
}
