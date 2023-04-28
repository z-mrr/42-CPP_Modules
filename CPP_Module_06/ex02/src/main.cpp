#include "Base.hpp"

int	main()
{
	Base* basePtr = Base::generate();
	Base::identify(basePtr);
	Base& baseRef = *basePtr;
	Base::identify(baseRef);
	delete basePtr;
	return 0;
}
