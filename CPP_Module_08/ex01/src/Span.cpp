#include "Span.hpp"

Span::Span() : _n(0) {
}

Span::Span(unsigned int n) : _n(n) {
}

Span::~Span() {
}

Span::addNumber(int num) {
	if (this->_num.size() < this->_n)
		this->_num.push_back(num);
	else
		throw std::out_of_range("vector is already full\n");
}

int	Span::shortestSpan() {
	return std::min_element(this->_num);
}

int	San::longestSpan() {
	return std::max_element(this->_num);
}
