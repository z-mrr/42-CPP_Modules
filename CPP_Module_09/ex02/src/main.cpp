#include "PmergeMe.hpp"

bool	isValid(const string& str) {
	if (!str.size())
		return 0;
	for (int i = 0; str[i]; i++) {
		if (!std::isdigit(str[i]))
			return 0;
	}
	char*	endptr;
	long long int num = std::strtoll(str.c_str(), &endptr, 10);
	if (*endptr != '\0' || num > numeric_limits<int>::max() || num <= 0) {
		return 0;
	}
	return 1;
}

int	main(int ac, char** av) {
	if (ac == 1) {
		cerr << "Error\n";
		return 1;
	}
	std::vector<int>	vctCnt;
	std::list<int>		lstCnt;
	int					num;
	for (int i = 1; i < ac; i++) {
		if (!isValid(string(av[i]))) {
			cerr << "Error\n";
			return 1;
		}
		num = atoi(av[i]);
		vctCnt.push_back(num);
		lstCnt.push_back(num);
	}
	try {
		PmergeMe	vec(vctCnt);
		PmergeMe	lst(lstCnt);
	} catch (std::exception &e) {
		cerr << e.what() << '\n';
	}
	return 0;
}

