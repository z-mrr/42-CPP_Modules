#include "ScalarConverter.hpp"

int	main(int ac, char** av)
{
	if (ac != 2)
	{
		cout << "./convert <value>\n";
		return 1;
	}
	try
	{
		ScalarConverter::convert(static_cast<string>(av[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
