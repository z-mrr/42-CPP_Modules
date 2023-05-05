#include "iter.hpp"

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
	int	a[4] = {1, 2, 3, 4};
	iter(a, 4, printValue);
	cout << '\n';

	Test	b[4] = {1, 2, 3, 4};
	iter(b, 4, printValue);
	cout << '\n';

	char	c[] = "Hi!";
	iter(c, 4, printValue);
	return 0;
}

