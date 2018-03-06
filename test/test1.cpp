#include <iostream>

void func(){
	int a;
	std::cin >> a;
//	std::cout << "a = " << a;
	if (a) {
		func();
		std::cout << a << ' ';
	}

}

int main(){

	std::cout << "func in" << std::endl;
	func();
	std::cout << "func out" << std::endl;

	return 0;
}
