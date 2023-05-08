#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;

template<typename T>
int	easyfind(T const& cont, int toFind) {
	vector<int>::const_iterator	it = std::find(cont.begin(), cont.end(), toFind);
	if (it != cont.end())
		return std::distance(cont.begin(), it);
	throw std::out_of_range("Couldn't find it!");
}

#endif
