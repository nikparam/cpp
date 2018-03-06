#include <iostream>
#include <cstdlib>

int main(){

	int i = 0, N = 0;
	char c = '\0';
	char * a  = (char * ) malloc(1 * sizeof(char) ) ;
	a[0] = '\0';
//	std::cout << a[0] << std::endl;

/*	for ( int i = 0; std::cin.get(c); ++i){
		if ( c == '\n' ) continue;
		else std::cout << " element number " << i << " is equal to " << c << std::endl;
	}*/

	for( i = 0 ; std::cin.get(c); a[i] = c, ++i ){
		if ( c == '\n' ) break;
		else a = ( char * ) realloc(a, ( i + 2 ) * sizeof(char) );
		N += 1;
	}
	for( i = 0 ; i < N; ++i ){
		std::cout << " a [ " << i << " ] = " << a[i] << std::endl; 
	}
	free(a);
	a = '\0';
	return 0;
}
