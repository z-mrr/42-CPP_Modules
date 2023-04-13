#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat a("Tone", 1);
		std::cout << a;
		a.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat a("Tone", 150);
		std::cout << a;
		a.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat a("Tone", 0);
		std::cout << a;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	try
	{
		Bureaucrat a("Tone", 151);
		std::cout << a;
	}
	catch (...)
	{
		std::cerr << "Caught some error\n";
	}
	try
	{
		Bureaucrat a("Tone", 42);
		std::cout << a;
		a.incrementGrade();
		std::cout << a;
		a.decrementGrade();
		std::cout << a;
	}
	catch (...)
	{
		std::cerr << "Caught some error\n";
	}
	return 0;
}
