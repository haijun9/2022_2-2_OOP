#include <stdio.h>
#include <iostream>

using namespace std;	// ǥ�� ���ӽ����̽� ���

struct CustomException : public std::exception {	// struct�� ������ Exception
private:
	int integer;	// ���Ȯ���� ���� ���� integer
public:
	CustomException(int i) { integer = i; }	// �Է¹��� i�� integer�� �Ҵ��ϴ� �޼ҵ�
	int what() { return integer; }	// integer�� ��ȯ�ϴ� �޼ҵ�
};

int main() {
	try {
		throw CustomException(10);	// 10�� �־� CustomExce ption �߻�
	}
	catch (CustomException ce) {	// ce catch �� what() �޼ҵ�� integer�� Ȯ��
		std::cout << "My exception number : " << ce.what() << std::endl;
	}
}