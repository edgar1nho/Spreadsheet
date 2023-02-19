#include "Tester.h"

void Tester::testCellValues()
{
	Cell c{};

	std::cout << "test for ToInt's\n";
	c.setValue("15");
	if (c.toInt() != 15)
	{
		std::cout << "test failed\n";
	}
	else
	{
		std::cout << "test passed\n";
	}
	
	c.setValue("-17");
	if (c.toInt() != -17)
	{
		std::cout << "test failed\n";
	}
	else
	{
		std::cout << "test passed\n";
	}

	std::cout << "test for ToDouble's\n";

	c.setValue("6");
	if (c.toDouble() != 6)
	{
		std::cout << "test failed\n";
	}
	else
	{
		std::cout << "test passed\n";
	}
	c.setValue("-6");
	if (c.toDouble() != -6)
	{
		std::cout << "test failed\n";
	}
	else
	{
		std::cout << "test passed\n";
	}
	c.setValue("6.7");
	if (c.toDouble() != 6.7)
	{
		std::cout << "test failed\n";
	}
	else
	{
		std::cout << "test passed\n";
	}
	c.setValue("-6.7");
	if (c.toDouble() != -6.7)
	{
		std::cout << "test failed\n";
	}
	else
	{
		std::cout << "test passed\n";
	}
}