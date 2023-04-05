#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <new>

// if the base class destructor isn’t marked as virtual, then the program is at risk for leaking memory if a programmer later deletes a base class pointer that is pointing to a derived object. One way to avoid this is to mark all your destructors as virtual. But should you?
// It’s easy to say yes, so that way you can later use any class as a base class -- but there’s a performance penalty for doing so (a virtual pointer added to every instance of your class). So you have to balance that cost, as well as your intent.

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
	Cat catCopy(cat);
	std::cout << '\n' << cat.getType() << " | " << catCopy.getType() << '\n';
	cat.printIdea(0);
	cat.printIdea(1);
	catCopy.printIdea(0);
	catCopy.printIdea(1);
	std::cout << '\n';
	Cat a = cat;
	return 0;
}
