#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat b("Tone", 5);
		std::cout << b;

		Form	f("Bicla", 7, 5);
		std::cout << f;

		b.signForm(f);
		b.signForm(f);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}

	return 0;
}
