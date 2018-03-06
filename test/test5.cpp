#include <iostream>

void strcat(char * to, const char * from){
	for (; * to ; ++to)
		{
//				std::cout << * p << std::endl;
		}
	for ( ; * from ; ++i, ++from )
	{
		* to = * from;
	}
}


int main(){
	char a[10] = "1 2 3 ";
	const char b[] = " 1 2 3 ";

	strcat( a, b );
	std::cout << a << std::endl;
}
