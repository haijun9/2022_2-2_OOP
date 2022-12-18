#include <iostream>
#include <cassert>

class CEO {		// CEO Ŭ����
public: virtual void what() { std::cout << "CEOClass" << std::endl; };	// virtual �Լ�
};

class CPO : public CEO{	// CPO Ŭ���� (CEO ���)
public: virtual void what() { std::cout << "CPOClass" << std::endl; };	// virtual �Լ� ���� + virtual ����
};

class Manager : public CEO, public CPO{	// Manager Ŭ���� (CEO, CPO ���)
public: virtual void what() { std::cout << "ManagerClass" << std::endl; };	// virtual �Լ� ���� + virtual ����
};

class Staff : public Manager {	// Staff Ŭ���� (Manager ���)
public: void what() { std::cout << "StaffClass" << std::endl; };	// virtual �Լ� ����
};
 
int main() {
	CPO* cpo = new Staff;							// CPO* �����ϰ� Staff �Ҵ�		(�ǽ� 3�� ����)
	Staff* staff = dynamic_cast<Staff*>(cpo);		// Staff* �����ϰ� dynamic_cast (�ǽ� 3�� ����)

	Manager* manager = dynamic_cast<Manager*>(cpo);	// Manager* �����ϰ� dynamic_cast (downcast)
	CEO* ceo = dynamic_cast<CEO*>(cpo);				// CEO* �����ϰ� dynamic_cast (upcast)

	assert(typeid(cpo) == typeid(Staff*));			// assert�� typeid �� -> ������ abort()
	delete cpo;										// �������� cpo �ʱ�ȭ
}