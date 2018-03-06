#include <iostream>

unsigned strlen( const char * str){
	const char * p = str;
	while ( * str ++ )
		{ 
			std::cout << *str ;
		 } 
	std::cout << std::endl;
	return str - p - 1;
}

int main(){

	const char s[] = "This is a very long string";
//	const char s[] = "Nikita";
	std::cout << s << std::endl;

	int len = strlen( &s[0] );

	std::cout << " Length of string : " << s << " -- equals to : " << len << std::endl;
}
