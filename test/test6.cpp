#include <iostream>

int strstr( const char * text, const char * pattern){

	bool exists = false;
	if ( !( * pattern ) ) return 0;
	for ( int i = 0; text[i]; ++i ){
		for ( int j = 0; pattern[j]; ++j ) {
			if ( pattern[j] != text[ i+j ] ) { exists = false; break; }
			else exists = true;
	}
		if ( exists ) return i ;
	}

	return -1;
}

int main(){
	const char str[] = "abcab";
	const char substr[] = "bc";
	int pos = strstr( str, substr );
	std::cout << pos << std::endl;
	return 0;
}
