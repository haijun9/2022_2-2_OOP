#include <iostream>
int& increment(int &x) // ���۷��� Ȱ��, ��ȯ
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