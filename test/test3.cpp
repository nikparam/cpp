#include <iostream>

bool max_element ( int * p, int * q, int ** result ){
	if ( p == q ) return false;

	* result = p;

	for ( ; p != q; ++p ){
		if ( * p > ** result) *result = p;
	}
	return true;
}

int main(){
	int i = 0, N;
	std::cin >> N;

	int a[N];
	int * q = a + N;
	for( int * p = a; p != q; ++p ){
		* p = ++ i ;
		std::cout << "a[ " << i - 1 << " ] = " << * p << std::endl;
	}

	int * pmax = 0;
	( max_element ( a, q, &pmax ) ) ? //
		std::cout << "Maximum = " << * pmax << std::endl : //
		std::cout << " Array is empty :(" << std::endl;
	return 0;
}
