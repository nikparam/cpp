#include <iostream>
#include <fstream>
#include <cmath>

double potential( double x ){

	if ( std::abs( x ) <=  1 ) { return 0.0; }

	return 0.0;
}

double boundary_cond( int nx, double A, double dx, double energy ){

	double psi0, psi1, f, q0, q1, q2;

	psi0 = 0;
	psi1 = A;

	f = 2.0 * ( potential( 0 ) - energy );
	q0 = psi0 * ( 1 - dx * dx * f / 12 );

	f = 2.0 * ( potential( dx ) - energy );
	q1 = psi1 * ( 1 - dx * dx * f / 12 );

	for( int i = 2; i <= nx; ++i ){

		q2 = dx * dx * f * psi1 + 2.0 * q1 - q0;
		q0 = q1;
		q1 = q2;
		f = 2.0 * ( potential( dx * i ) - energy );
		psi1 = q1 / ( 1.0 - dx * dx * f );
	}

	return psi1;
}

int main(){

	int nx = 1000;
	double A = 0.01, left = -1, right = 1;
	double dx, q0, q1, q2, f, energy1, energy2, energy3;
	dx = ( right - left ) / nx;

	double sum = 0.0, psi1, psi2, psi3;

	double * psi = new double[ nx ];
	std::ofstream fout;
	fout.open( "out.out" );


	energy1 = 15;
	energy2 = 5;

	std::cout << "Left energy = " << energy1 << "; psi[ " << nx - 1 << " ] = " << boundary_cond(nx,A,dx,energy1) << std::endl;
	std::cout << "Right energy = " << energy2 << "; psi[ " << nx - 1 << " ] = " << boundary_cond(nx,A,dx,energy2) << std::endl;

	do{
		energy3 = 0.5 * ( energy1 + energy2 );
		psi3 = boundary_cond(nx,A,dx,energy3);

		if ( psi3 <= 0 ) { energy1 = energy3; }
		else { energy2 = energy3; }

		std::cout << "Energy = " << energy3 << ", psi[ " << nx - 1  <<  " ] = " << psi3 << std::endl ;

	}while( std::abs( energy1 - energy2 ) > 1e-6 );


	for( int i = 0; i <= nx; ++i ){ psi[i] = boundary_cond( i, A, dx, energy3 ); }

	for( int i = 0; i <= nx; ++i ){ sum += psi[ i ] * psi[ i ]; }

	sum *= dx;
	sum = std::sqrt( sum );
	std::cout << "Integral = " << sum << std::endl;

	for( int i = 0; i <= nx; ++i ) { 
		psi[ i ] /= sum;
		fout << left << " " << psi[ i ] << std::endl;
		left += dx;
	}

	fout.close();
	return 0;

}
