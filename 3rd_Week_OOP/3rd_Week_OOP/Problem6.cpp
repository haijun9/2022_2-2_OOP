#include<iostream>
void swap(int& first, int& second) // 인자를 레퍼런스로 활용
{
	int temp = first;
	first = second;
	second = temp;
}
int main()
{
	int a = 2, b = 3;
	swap(a, b);
	std::cout << a << " " << b << std::endl;
	return 0;
}