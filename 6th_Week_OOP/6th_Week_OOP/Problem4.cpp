#include <stdio.h>
#include <iostream>
#include <string>

class Person {
private:
	std::string name;		// 이름 변수
	int age;				// 나이 변수
	std::string address;	// 주소 변수

public:
	Person(std::string Name, std::string Address, int Age) :
		name(Name), address(Address), age(Age) {};	// 입력받은 값으로 수정하는 생성자
	
	std::string getName() { return name; };			// 이름 반환하는 메소드
	std::string getAddress() { return address; };	// 주소 반환하는 메소드
	int getAge() { return age; };					// 나이 반환하는 메소드
}; 

class Student : public Person {		// Person을 상속받는 Student Class
private:
	std::string ID;			// 학번 변수 추가
public:
	Student(std::string Name, std::string Address, int Age, std::string Id) :
		Person(Name, Address, Age), ID(Id) {}; // 입력받은 값으로 수정하는 생성자

	std::string getID() { return ID; }; // 학번 반환하는 메소드
};

int main() {
	Student man("Jeon HaeJun", "daejeon", 10, "201902748"); 
	// 정보 입력한 Student 객체 man 생성
	
	std::cout << "Student Information" << std::endl;			// man 정보 출력
	std::cout << "Name : " << man.getName() << std::endl;		// 이름 출력
	std::cout << "Age : " << man.getAge() << std::endl;			// 나이 출력
	std::cout << "Address : " << man.getAddress() << std::endl; // 주소 출력
	std::cout << "Student ID : " << man.getID() << std::endl;	// 학번 출력
}