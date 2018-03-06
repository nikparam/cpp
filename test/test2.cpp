#include <iostream>

void rotate( int a[], unsigned size, int shift ){
	int i = 0, j = 0;
	int t = 0;

	shift = ( shift >= ( size + 1 ) ) ? shift % ( size + 1 ) : shift;

	std::cout << "Internal shift = " << shift << std::endl;
	if (!shift) return;
	for ( j = 0; j < shift; j++){
		for ( i = 0; i < size; i++ ){
			t = a[i];
			a[i] = a[i+1];
			a[i+1] = t;
		}
	}
}

int main(){

	int shift = 0;
	while ( std::cin >> shift ){
		std::cout << "shift = " << shift << std::endl;
		int a[5] = { 1, 2, 3, 4, 5 };
		int * p = &a[0];
		int * q = &a[4];
		std::cout << std::endl;
		rotate( a, ( q - p ), shift );
		for ( p; p <= q; ++p){
			std::cout << *p << std::endl;
		}
		std::cout << std::endl;
	}
}
