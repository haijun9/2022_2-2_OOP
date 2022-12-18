#include <iostream>
int& func(int& a) { return a; } // 레퍼런스 반환으로 수정
int main() {
	int x = 1;
	std::cout << func(x)++ << std::endl;
	std::cout << x << std::endl;
}