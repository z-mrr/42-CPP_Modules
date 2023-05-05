#include "Array.hpp"

int	main() {
	Array<int> a;
	cout << "a size = " << a.size() << '\n';

	Array<int> b(4);
	Array<int> c(b);
	a = b;
	cout << "a size = " << a.size() << '\n';
	cout << "b size = " << b.size() << '\n';
	cout << "c size = " << c.size() << '\n';
	try
	{
		a[1] = 4;
		c[4] = 4;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}
