#include <stdio.h>
#include <iostream>

class A{	// operator overloading�� ������ class A
public:
	int x;	// ������ ��� ���� x
	A(int i) { x = i; };	// �Է¹��� i�� x�� �Ҵ��ϴ� ������
	int getNum() { return x; };	// x���� ��ȯ�ϴ� �޼ҵ�
	
	A operator++(int i) { // postfix unary �޼ҵ�, i�� ���п�
		++(this->x);		// ++x ���� 
		return *this;		// A ��ü tmp ��ȯ
	}
	
	A operator++() { // prefix unary �޼ҵ� 
		x++;			// x++ ����
		return *this;	// ���Ǵ� ���� �ּ��� ���۷��� ��ȯ
	}
};
int main() {
	A obj(5);			// �ʱⰪ 5�� ����
	std::cout<< "�ʱⰪ : " << obj.getNum() << std::endl;	// �ʱⰪ ���
	obj++;	// x++ ����
	std::cout << "a++ ��� : " << obj.getNum() << std::endl;	// x++ ��� ���
	++obj;	// ++x ����
	std::cout << "++a ��� : " << obj.getNum() << std::endl;	// ++x ��� ���
}