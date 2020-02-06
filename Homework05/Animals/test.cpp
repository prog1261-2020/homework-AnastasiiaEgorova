#include "gtest/gtest.h"
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Duck.h"
#include <iostream>

TEST(TestCaseName, TestName) {
	Animal cat("Sabrina", "cat", "meow");
	Animal dog("Fido", "dog", "gav");
	Animal duck("Donald", "duck", "quack");

	Cat cat2("Johnny");
	Dog dog2("Bars");
	Duck duck2("Fred");

	std::cout << "\n\n";
	cat.speak();
	cat2.speak();
	dog.speak();
	dog2.speak();
	duck.speak();
	duck2.speak();

	std::cout << "\n\n";

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}