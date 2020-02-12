#include "gtest/gtest.h"
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Duck.h"
#include "Capybara.h"
#include "Alpaca.h"
#include <iostream>
#include <vector>
#include <memory>

TEST(TestCaseName, TestName) {
	std::vector<std::unique_ptr<Animal>> zoo;
	
	zoo.push_back(std::make_unique<Cat>("Fluffy"));
	zoo.push_back(std::make_unique<Dog>("Fido"));
	zoo.push_back(std::make_unique<Duck>("Daffy"));
	zoo.push_back(std::make_unique<Capybara>("Fred"));
	zoo.push_back(std::make_unique<Alpaca>("Zooey"));
	//the same as Animal* a = &Cat;

	std::cout << "\n";
	for (auto& a : zoo) {
		a->speak();

		//do not downcast!!!
		//((Duck*)a.get())->swim();

		a->move();

		std::cout << "\n";
	}
	std::cout << "\n";


	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}