#include <stdio.h>
#include <iostream>

class A : public std::exception{
public:
	A() {	// A ������
		std::cout << "Constructor()" << std::endl; // ���� Ȯ�ο� ���
	};
	~A() {	// A �Ҹ���
		std::cout << "Destructor()" << std::endl; // �Ҹ� Ȯ�ο� ���
	};
};

int main() { 
	try {
		A object;	// A ��ü object
		throw 10;	// ���� ���� 10 throw
	}
	catch (int i) {	// ������ ���� catch
		std::cout << "Catch " << i << std::endl;	// ���� ���� ���
	}
}