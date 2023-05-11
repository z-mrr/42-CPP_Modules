#include "Span.hpp"

int main()
{
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "\nsubject" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		cout << '\n';
	} catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	} try {
		Span sp = Span(10000);
		std::cout << "empty vec" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		cout << '\n';
	} catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	} try {
		Span sp = Span(1);
		std::cout << "full vec" << std::endl;
		sp.addNumber(6);
		sp.addNumber(6);
		cout << '\n';
	} catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	} try {
		Span sp = Span(2);
		sp.addNumber(-2000000000);
		sp.addNumber(-6);
		Span cp(sp);
		std::cout << "copy constructor" << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		cout << '\n';
	} catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}  try {
		Span sp(20000);
		std::vector<int> vec;
		std::srand(std::time(0));
		for (int i = 0; i < 20000; ++i) {
			int rndInt = std::rand();
			vec.push_back(rndInt);
		}
		std::cout << "20 000 ints" << std::endl;
		// sp.addNumber(0);
		sp.addNumbers(vec.begin(), vec.end());
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		cout << '\n';
	} catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
