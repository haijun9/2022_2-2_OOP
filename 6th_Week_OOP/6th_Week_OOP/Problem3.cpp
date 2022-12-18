#include <stdio.h>
#include <iostream>

class A : public std::exception{
public:
	A() {	// A 생성자
		std::cout << "Constructor()" << std::endl; // 생성 확인용 출력
	};
	~A() {	// A 소멸자
		std::cout << "Destructor()" << std::endl; // 소멸 확인용 출력
	};
};

int main() { 
	try {
		A object;	// A 객체 object
		throw 10;	// 예외 변수 10 throw
	}
	catch (int i) {	// 정수인 예외 catch
		std::cout << "Catch " << i << std::endl;	// 예외 내용 출력
	}
}