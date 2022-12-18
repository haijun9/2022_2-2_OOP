class Animal {
public:
	Animal() {}	//blank 생성자 구현
	Animal(int numberOfLeg) {
		this->numberOfLeg = numberOfLeg;
	}
private:
	int numberOfLeg;
};
 
int main() {
	Animal a;
	return 0;
}