#include "Span.hpp"

Span::Span() : _n(0) {
}

Span::Span(unsigned int n) : _n(n) {
}

Span::Span(Span const& other) {
	*this = other;
}

Span::~Span() {
}

Span&	Span::operator=(Span const& other) {
	if (this != &other) {
		_n = other._n;
		_vec = other._vec;
	}
	return *this;
}

void	Span::addNumber(int num) {
	if (_vec.size() < _n)
		_vec.push_back(num);
	else
		throw std::out_of_range("vector is already full\n");
}

void	Span::addNumbers(vector<int>::iterator it, vector<int>::iterator ite) {
	if (_n - static_cast<unsigned int>(_vec.size()) < static_cast<unsigned int>(std::distance(it, ite)))
		throw std::out_of_range("range too big for vector\n");
	std::copy(it, ite, std::back_inserter(_vec));
	// _vec.insert(_vec.end(), it, ite);
}

unsigned int	Span::shortestSpan() {
	if (_vec.size() < 2)
		throw std::out_of_range("N < 2\n");
	unsigned int	ret = UINT_MAX; // UINT_MAX = abs(INT_MAX - INT_MIN)
	unsigned int	tmp;
	vector<int>	cpy(_vec);
	std::stable_sort(cpy.begin(), cpy.end()); // stable keeps the order for = values
	for (vector<int>::iterator it = cpy.begin(); it + 1 != cpy.end(); it++) {
		tmp = static_cast<unsigned int>(abs(*(it + 1) - *it));
		if (tmp < ret)
			ret = tmp;
	}
	return ret;
}

unsigned int	Span::longestSpan() {
	if (_vec.size() < 2)
		throw std::out_of_range("N < 2\n");
	vector<int>::iterator	imin = std::min_element(_vec.begin(), _vec.end());
	vector<int>::iterator	imax = std::max_element(_vec.begin(), _vec.end());
	return static_cast<unsigned int>(abs(*imax - *imin));
}
