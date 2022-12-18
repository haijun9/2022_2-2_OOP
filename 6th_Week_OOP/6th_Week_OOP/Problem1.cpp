#include <stdio.h>
#include <iostream>

class A{	// operator overloading이 구현될 class A
public:
	int x;	// 정수가 담길 변수 x
	A(int i) { x = i; };	// 입력받은 i를 x에 할당하는 생성자
	int getNum() { return x; };	// x값을 반환하는 메소드
	
	A operator++(int i) { // postfix unary 메소드, i는 구분용
		++(this->x);		// ++x 수행 
		return *this;		// A 객체 tmp 반환
	}
	
	A operator++() { // prefix unary 메소드 
		x++;			// x++ 수행
		return *this;	// 계산되는 본인 주소의 레퍼런스 반환
	}
};
int main() {
	A obj(5);			// 초기값 5로 생성
	std::cout<< "초기값 : " << obj.getNum() << std::endl;	// 초기값 출력
	obj++;	// x++ 수행
	std::cout << "a++ 결과 : " << obj.getNum() << std::endl;	// x++ 결과 출력
	++obj;	// ++x 수행
	std::cout << "++a 결과 : " << obj.getNum() << std::endl;	// ++x 결과 출력
}