#include <iostream>

class Test {
public:
	int num1;
	int num2;

	Test(int a, int b) { //持失切 拙失
		num1 = a;
		num2 = b;
	}
	 
	void print() {
		std::cout << "num1 : " << num1 << std::endl;
		std::cout << "num2 : " << num2 << std::endl;
	}
};

int main() {
	Test a = Test(1, 3);
	a.print();
}