#include <iostream>
void increment(int* x) // 포인터 활용
{
	++(*x);
}
int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	increment(&x); // 주소 전달
	std::cout << " After increment: " << x << std::endl;
	system("pause");
	return 0;
}