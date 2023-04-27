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

// dá erro se o tipo do input nao for válido segundo o subject: por ser desconhecido, ou por ultrapassar os limites do tipo
// checka os limites nas conversoes. apenas o max e o lower, nao faz o min() de double para float pois nao faria sentido
// mensagens variaveis apos conversao para char: caso passe os limites, ou nao seja printavel
// parametro variavel na funçao overLimit()
// strtold para converter string em double long antes dos checks.
// atoi, strtof, strtod para converter string em int, float e double respetivamente, depois dos checks
