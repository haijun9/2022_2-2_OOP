#include <stdio.h>
#include <iostream>
#include <string>

class Person {
private:
	std::string name;		// �̸� ����
	int age;				// ���� ����
	std::string address;	// �ּ� ����

public:
	Person(std::string Name, std::string Address, int Age) :
		name(Name), address(Address), age(Age) {};	// �Է¹��� ������ �����ϴ� ������
	
	std::string getName() { return name; };			// �̸� ��ȯ�ϴ� �޼ҵ�
	std::string getAddress() { return address; };	// �ּ� ��ȯ�ϴ� �޼ҵ�
	int getAge() { return age; };					// ���� ��ȯ�ϴ� �޼ҵ�
}; 

class Student : public Person {		// Person�� ��ӹ޴� Student Class
private:
	std::string ID;			// �й� ���� �߰�
public:
	Student(std::string Name, std::string Address, int Age, std::string Id) :
		Person(Name, Address, Age), ID(Id) {}; // �Է¹��� ������ �����ϴ� ������

	std::string getID() { return ID; }; // �й� ��ȯ�ϴ� �޼ҵ�
};

int main() {
	Student man("Jeon HaeJun", "daejeon", 10, "201902748"); 
	// ���� �Է��� Student ��ü man ����
	
	std::cout << "Student Information" << std::endl;			// man ���� ���
	std::cout << "Name : " << man.getName() << std::endl;		// �̸� ���
	std::cout << "Age : " << man.getAge() << std::endl;			// ���� ���
	std::cout << "Address : " << man.getAddress() << std::endl; // �ּ� ���
	std::cout << "Student ID : " << man.getID() << std::endl;	// �й� ���
}