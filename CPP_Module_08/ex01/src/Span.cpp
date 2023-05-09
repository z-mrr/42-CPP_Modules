#include "Span.hpp"

Span::Span() : _n(0) {
}

Span::Span(unsigned int n) : _n(n) {
}

Span::~Span() {
}

void	Span::addNumber(int num) {
	if (this->_num.size() < this->_n)
		this->_num.push_back(num);
	else
		throw std::out_of_range("vector is already full\n");
}

int	Span::shortestSpan() {
	//2nd min - min
	//sort?
	return 1;
}

int	Span::longestSpan() {
	//max - min
	//std::minmax_element
	return 1;
}
