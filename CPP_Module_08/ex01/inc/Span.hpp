#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::vector;

class Span {
public:
	Span(unsigned int n);
	Span(Span const& other);
	~Span();
	Span&			operator=(Span const& other);

	void			addNumber(int num);
	void			addNumbers(vector<int>::iterator it, vector<int>::iterator ite);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

private:
	Span();


	unsigned int	_n;
	vector<int>		_vec;
};

#endif
