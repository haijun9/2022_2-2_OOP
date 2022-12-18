#include <iostream>

class BaseClass {	// 기본 BaseClass
public: virtual void what() {std::cout << "BaseClass" << std::endl;};	// virtual 함수
};
 
class DerivedClass : public BaseClass{	// 상속하는 DerivedClass (BaseClass 상속)
public: void what() {std::cout << "DerivedClass" << std::endl;};	// virtual 함수 수정
};

int main() {
	BaseClass baseclass;				// BaseClass baseclass 선언
	DerivedClass derivedclass;			// DerivedClass derivedclass 선언

	BaseClass* base = &derivedclass;	// BaseClass* 선언과 DerivedClass 할당
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base);	// DerivedClass* 선언과 dynamic_cast

	if (derived != nullptr) std::cout << "Everything is OKAY" << std::endl;	// derived가 nullptr가 아닌 경우 == 인스턴스 생성 성공
	else std::cout << "Runtime Error" << std::endl;	// nullptr인 경우 == 인스턴스 생성 실패
	
	return 0;
}