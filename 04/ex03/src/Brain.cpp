#include "Brain.hpp"
#include <cstdio>

Brain::Brain()
{
	char n[3];

	std::cout << "Brain constructor called.\n";
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "Not an original idea nr.";
		std::sprintf(n, "%d", i);
		ideas[i].append(n);
		ideas[i].append("\n");
	}
}

Brain::Brain(const Brain& ref)
{
	std::cout << "Brain copy constructor called.\n";
	*this = ref;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called.\n";
}

Brain&	Brain::operator=(const Brain& ref)
{
	if (this != &ref)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = ref.ideas[i];
	return *this;
}
