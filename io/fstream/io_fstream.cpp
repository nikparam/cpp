#include <iostream>
#include <fstream>

int main()
{
	int a = 0, b = 0;

	std::ifstream fin;

	fin.open( "../data.txt" );
	fin >> a >> b;
	fin.close();
	std::cout << " a + b = " << a + b << std::endl;
	return 0;
}
