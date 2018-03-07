#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::vector;

double potential( double x ){

	if ( std::abs( x ) <=  1 ) { return 0.0; }

	return 0.0;
}

vector<double> calculate_wave_function( int nx, double A, double dx, double energy )
{
	vector<double> result(nx + 1);
	result[0] = 0;
	result[1] = A;
	
	double f = 2.0 * (potential(0) - energy);
	double q0 = result[0] * (1 - dx*dx*f / 12);

	f = 2.0 * ( potential(dx) - energy );
	double q1 = result[1] * (1 - dx * dx * f / 12);
	double q2;

	for ( int i = 2; i <= nx; ++i )
	{
		q2 = dx * dx * f * result[i-1] + 2.0 * q1 - q0; // dx * dx * f(0) * psi(0) + 2 * q(0) - q(-dx)
		q0 = q1; // q(-dx) <- q(0)
		q1 = q2; // q(0) <- q(dx)
		f = 2.0 * ( potential( dx * i ) - energy ); // f(0) <- f(dx)
		result[i] = q1 / ( 1.0 - dx * dx * f / 12.0 ); 
	}

	return result;
}

double boundary_cond( int nx, double A, double dx, double energy ){

	double psi0, psi1, f, q0, q1, q2;

	psi0 = 0; // psi(-dx)
	psi1 = A; // psi(0)

	f = 2.0 * ( potential( 0 ) - energy ); // f(-dx)
	q0 = psi0 * ( 1 - dx * dx * f / 12 ); // q(-dx)

	f = 2.0 * ( potential( dx ) - energy ); // f(0)
	q1 = psi1 * ( 1 - dx * dx * f / 12 ); // q(0)

	for( int i = 2; i <= nx; ++i ){

		q2 = dx * dx * f * psi1 + 2.0 * q1 - q0; // dx * dx * f(0) * psi(0) + 2 * q(0) - q(-dx)
		q0 = q1; // q(-dx) <- q(0)
		q1 = q2; // q(0) <- q(dx)
		f = 2.0 * ( potential( dx * i ) - energy ); // f(0) <- f(dx)
		psi1 = q1 / ( 1.0 - dx * dx * f / 12.0 ); 
	}

	return psi1;
}

int main(){

	int nx = 1000;
	double A = 0.01, left = -1, right = 1;
	double dx, energy1, energy2, energy3;
	dx = ( right - left ) / nx;

	double sum = 0.0, psi3;

	const double epsilon = 1e-10;

	std::ofstream fout( "out.out" );

	std::cin >> energy1;
	std::cin >> energy2;

	double psi1 = boundary_cond( nx, A, dx, energy1 );
	double psi2 = boundary_cond( nx, A, dx, energy2 );

	std::cout << "Left energy = " << energy1 << "; psi[ " << nx - 1 << " ] = " << psi1<< std::endl;
	std::cout << "Right energy = " << energy2 << "; psi[ " << nx - 1 << " ] = " << psi2 << std::endl;

	std::cout << std::fixed << std::setprecision(10);
	do{
		energy3 = 0.5 * ( energy1 + energy2 );
		psi3 = boundary_cond(nx,A,dx,energy3);

		if ( psi1 < 0 )
		{
			if ( psi3 < 0 ) { energy1 = energy3; }
			else if ( psi3 > 0 ) { energy2 = energy3; }
			else break;
		}
		
		if ( psi1 > 0 )
		{
			if ( psi3 > 0 ) { energy1 = energy3; }
			else if ( psi3 < 0 ) { energy2 = energy3; }
			else break;
		}	 

		std::cout << "Energy = " << energy3 << ", psi[ " << nx - 1  <<  " ] = " << psi3 << std::endl ;

	} while( !( std::abs( energy1 - energy2 ) < epsilon && std::abs( psi3 ) < epsilon ) );

	
	vector<double> psi = calculate_wave_function( nx, A, dx, energy3 );
	
	for( int i = 0; i <= nx; ++i ){ sum += psi[ i ] * psi[ i ]; }

	sum *= dx;
	sum = std::sqrt( sum );
	std::cout << "Integral = " << sum << std::endl;

	std::transform( psi.begin(), psi.end(), psi.begin(), [=](double x){ return x / std::sqrt(sum); });
	for ( int k = 0; k <= nx; k++, left += dx )
		fout << left << " " << psi[k] << std::endl;

//	for( int i = 0; i <= nx; ++i ) { 
//		psi[ i ] /= sum;
//		fout << left << " " << psi[ i ] << std::endl;
//		left += dx;
//	}

	fout.close();

	return 0;

}
