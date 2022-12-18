#include <iostream>
#include <cassert>

class CEO {		// CEO 클래스
public: virtual void what() { std::cout << "CEOClass" << std::endl; };	// virtual 함수
};

class CPO : public CEO{	// CPO 클래스 (CEO 상속)
public: virtual void what() { std::cout << "CPOClass" << std::endl; };	// virtual 함수 수정 + virtual 유지
};

class Manager : public CEO, public CPO{	// Manager 클래스 (CEO, CPO 상속)
public: virtual void what() { std::cout << "ManagerClass" << std::endl; };	// virtual 함수 수정 + virtual 유지
};

class Staff : public Manager {	// Staff 클래스 (Manager 상속)
public: void what() { std::cout << "StaffClass" << std::endl; };	// virtual 함수 수정
};
 
int main() {
	CPO* cpo = new Staff;							// CPO* 선언하고 Staff 할당		(실습 3번 참고)
	Staff* staff = dynamic_cast<Staff*>(cpo);		// Staff* 선언하고 dynamic_cast (실습 3과 동일)

	Manager* manager = dynamic_cast<Manager*>(cpo);	// Manager* 선언하고 dynamic_cast (downcast)
	CEO* ceo = dynamic_cast<CEO*>(cpo);				// CEO* 선언하고 dynamic_cast (upcast)

	assert(typeid(cpo) == typeid(Staff*));			// assert로 typeid 비교 -> 같으면 abort()
	delete cpo;										// 동적변수 cpo 초기화
}