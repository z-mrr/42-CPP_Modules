#include "Base.hpp"

Base*	Base::generate()
{
	std::srand(std::time(0));
	int	choice = std::rand() % 3;
	switch (choice)
	{
	case 0:
		cout << "generated A\n";
		return new A;
	case 1:
		cout << "generated B\n";
		return new B;
	case 2:
		cout << "generated C\n";
		return new C;
	default:
		return NULL;
	}
}

void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		cout << "pointer to A\n";
	else if (dynamic_cast<B*>(p))
		cout << "pointer to B\n";
	else if (dynamic_cast<C*>(p))
		cout << "pointer to C\n";
	else
		cout << "Couldn't identify pointer\n";
}

void	Base::identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		cout << "reference to A\n";
	}
	catch (const std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
			cout << "reference to B\n";
		}
		catch (const std::exception& e)
		{
			try
			{
				dynamic_cast<C&>(p);
				cout << "reference to C\n";
			}
			catch (const std::exception& e)
			{
				cout << "Couldn't identify reference\n";
			}
		}
	}
}
