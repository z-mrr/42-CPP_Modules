#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		cerr << "Error: could not open file.\n";
		return 1;
	}
	string	input(av[1]);
	try {
		BitcoinExchange	btcExc(input);
		btcExc.process();
	} catch (std::exception &e) {
		cerr << e.what() << '\n';
	}
	return 0;
}
