#include <iostream>

int main()
{
	float foo = 6.0f;
	float* xv = &foo;
	
	std::cout << *xv << std::endl;
	std::cout << xv << std::endl;
	
	return 0;
}