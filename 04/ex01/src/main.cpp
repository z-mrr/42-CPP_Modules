#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <new>

int	main()
{
	Animal*	animal[100];

	for (int i = 0; i < 100; i++)
		i % 2 ? animal[i] = new Dog : animal[i] = new Cat;
	for (int i = 0; i < 100; i++)
	{
		std::cout << "(Animal " << i << ") " << animal[i]->getType() << ": ";
		animal[i]->printIdea(i);
	}
	std::cout << "\n\n";
	for (int i = 0; i < 100; i++)
		delete animal[i];

	std::cout << "\n\n";
	Cat	cat;
	cat.setIdea(0, "TEST 0\n");
	Cat catcopy(cat);
	std::cout << '\n';
	cat.printIdea(0);
	cat.printIdea(1);
	catcopy.printIdea(0);
	catcopy.printIdea(1);
	std::cout << '\n';
	return 0;
}
