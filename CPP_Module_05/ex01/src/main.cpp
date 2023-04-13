#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat b("Tone", 5);
		std::cout << b;

		Form	f("Bicla", 5);
		f.beSigned(b);
		std::cout << f;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}

	return 0;
}
