#include "RPN.hpp"
#include <iostream>
using std::cout;
using std::cerr;

int	main(int ac, char** av) {
	if (ac != 2 || !av[1] || !av[1][0]) {
		cerr << "Error\n";
		return 1;
	}
	try {
		RPN	solve(av[1]);
		cout << solve.process() << '\n';
	} catch (std::exception &e) {
		cerr << e.what() << '\n';
	}
	return 0;
}
