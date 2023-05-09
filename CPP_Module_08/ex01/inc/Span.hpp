#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;

class Span {
public:
	Span(unsigned int n);
	~Span();

	void	addNumber(int num);
	int		shortestSpan();
	int		longestSpan();

private:
	Span();
	//copy e operator=

	unsigned int	_n;
	vector<int>	_num;
};

#endif
