class Animal {
public:
	Animal() {}	//blank ������ ����
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