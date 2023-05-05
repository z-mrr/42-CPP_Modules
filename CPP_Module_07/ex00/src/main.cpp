#include "whatever.hpp"

class Test {
public:
	Test() : _n(0) {}
	Test(int n) : _n(n) {}
	Test(Test const& ref) {*this = ref;}
	~Test() {}
	Test&	operator=(Test const& ref) {
		if (this != &ref) {
			this->_n = ref._n;
		}
		return *this;
	}
	bool	operator<(Test const& ref) const {
		return this->getN() < ref.getN();
	}
	bool	operator>(Test const& ref) const {
		return this->getN() > ref.getN();
	}
	int	getN() const {return this->_n;}
private:
	int	_n;
};
std::ostream	&operator<<(std::ostream &o, Test const& ref) {
	o << ref.getN();
	return o;
}

int	main() {
	// float	a = 1, b = 2;
	// swap(a, b);
	// cout << a << '\n' << b << '\n';
	// cout << min(a, b) << '\n';
	// cout << max(a, b) << "\n\n";
	// Test	c(1), d(2);
	// swap(c, d);
	// cout << c << '\n' << d << '\n';
	// cout << min(c, d) << '\n';
	// cout << max(c, d) << '\n';

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}

