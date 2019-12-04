#include <iostream>

using namespace std;

#define PLUS(a, b) a##b
void temp1()
{
	cout << "temp1 function" << endl;
}
void temp2()
{
	cout << "temp2 function" << endl;
}
void temp21()
{
	cout << "1 and temp2 function" << endl;
}
int main()
{
	// std::cout << "plus result is :" << PLUS(temp1, temp2) << std::endl;
	PLUS(temp2, 1)();
	return 0;
}