#include <iostream>
int& func(int& a) { return a; } // ���۷��� ��ȯ���� ����
int main() {
	int x = 1;
	std::cout << func(x)++ << std::endl;
	std::cout << x << std::endl;
}