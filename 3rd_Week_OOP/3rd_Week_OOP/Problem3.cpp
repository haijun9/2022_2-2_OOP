#include <iostream>
int& increment(int &x) // 레퍼런스 활용, 반환
{
	return ++x;
}
int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	increment(x);
	std::cout << " After increment: " << x << std::endl;
	system("pause");
	return 0;
}