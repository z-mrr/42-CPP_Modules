#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <new>

int	main()
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << '\n';

	const WrongAnimal*	meta2 = new WrongAnimal();
		const Animal*	j2 = new Dog();
	const WrongAnimal*	i2 = new WrongCat();

	std::cout << j2->getType() << " " << std::endl;
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound(); //will output the wrong animal sound!
	j2->makeSound();
	meta2->makeSound();

	delete meta;
	delete meta2;
	delete j;
	delete j2;
	delete i;
	delete i2;

	return 0;
}
