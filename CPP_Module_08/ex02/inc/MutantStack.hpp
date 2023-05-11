#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::vector;

class MutantStack {
public:
	MutantStack();
	MutantStack(MutantStack const& other);
	~MutantStack();
	MutantStack&			operator=(MutantStack const& other);

private:
};

#endif
