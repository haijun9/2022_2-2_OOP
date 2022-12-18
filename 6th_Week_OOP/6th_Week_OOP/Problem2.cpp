#include <stdio.h>
#include <iostream>

using namespace std;	// 표준 네임스페이스 사용

struct CustomException : public std::exception {	// struct로 구현한 Exception
private:
	int integer;	// 결과확인을 위한 변수 integer
public:
	CustomException(int i) { integer = i; }	// 입력받은 i를 integer에 할당하는 메소드
	int what() { return integer; }	// integer를 반환하는 메소드
};

int main() {
	try {
		throw CustomException(10);	// 10을 넣어 CustomExce ption 발생
	}
	catch (CustomException ce) {	// ce catch 시 what() 메소드로 integer값 확인
		std::cout << "My exception number : " << ce.what() << std::endl;
	}
}