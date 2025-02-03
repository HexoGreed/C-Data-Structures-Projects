// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "frac.h"
int main()
{

	FractionType one;
	FractionType two;
	one.Initialize(2, 3);
	two.Initialize(4, 5);
	FractionType uno = one + two;
	FractionType dos = one * two;
	FractionType three = one / two;
	FractionType four = one - two;



	uno.print();
	std::cout << "uno^" << std::endl;

	dos.print();
	std::cout << "dos^" << std::endl;

	three.print();
	std::cout << "three^" << std::endl;

	four.print();
	std::cout << "four^" << std::endl;


	
}
