#include "easyfind.hpp"

int	main() {
	vector<int>	cont;
	for (int i = 0; i <= 42; i++) {
		cont.push_back(i);
	}
	try {
		cout << easyfind(cont, 13);
	} catch (std::exception const& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
