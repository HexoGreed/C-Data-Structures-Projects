#pragma once
#include <iostream>
#include <cmath>


using namespace std;


double NewtonSqrt(double x, double a = -1.0, double epslion = 1e-10) {
	if (a == -1.0) {
		a = x;
	}//doing this bc i cnat set a directly to x in its intialazation so im doing it first.

	//absolute valuuee
	if (fabs((a * a )- x) <= epslion) {
		return a;

	}
	else {
		double new_a = (a + x / a) / 2.0; 
		return NewtonSqrt(x, new_a, epslion);

	}

}