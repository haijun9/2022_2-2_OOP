#include <iostream>

class BaseClass {	// �⺻ BaseClass
public: virtual void what() {std::cout << "BaseClass" << std::endl;};	// virtual �Լ�
};
 
class DerivedClass : public BaseClass{	// ����ϴ� DerivedClass (BaseClass ���)
public: void what() {std::cout << "DerivedClass" << std::endl;};	// virtual �Լ� ����
};

int main() {
	BaseClass baseclass;				// BaseClass baseclass ����
	DerivedClass derivedclass;			// DerivedClass derivedclass ����

	BaseClass* base = &derivedclass;	// BaseClass* ����� DerivedClass �Ҵ�
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base);	// DerivedClass* ����� dynamic_cast

	if (derived != nullptr) std::cout << "Everything is OKAY" << std::endl;	// derived�� nullptr�� �ƴ� ��� == �ν��Ͻ� ���� ����
	else std::cout << "Runtime Error" << std::endl;	// nullptr�� ��� == �ν��Ͻ� ���� ����
	
	return 0;
}