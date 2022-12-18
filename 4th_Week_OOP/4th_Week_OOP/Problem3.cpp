#include <iostream>
using namespace std;

int i;

class A {
public:
	~A() { i = 10; }
};

int foo() { 
	i = 3;
	{A ob; }	//중괄호 이용
	return i;
}

int main() {
	cout << foo() << endl;
	return 0;
}