#include <iostream>
#include <fstream>
#include <cmath>

double function( double x ){

	return x * x;

}

int main(){

	double dx, left, right;
	double sum = 0.0;
	std::ifstream fin;
	fin.open( "input.inp" );

//	std::cout << "Input step: " << std::endl;
	fin >> dx;
//	std::cout << "Input left boundary: " << std::endl;
	fin >> left;
//	std::cout << "Input right boundary: " << std::endl;
	fin >> right;

	if ( left < right ){

		for ( ; left <= right; left += dx ){
			sum += function( left );
		}

		sum *= dx;

	}

	std::cout << "Integral = " << sum << std::endl;

	fin.close();

	return 0;

}

