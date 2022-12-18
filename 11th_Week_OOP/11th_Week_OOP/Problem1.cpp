#include <iostream>
#include <set>

class Set {
	std::set<int> s;
public:
	void insert(int i) { s.insert(i); }
	int getMax() { return *(s.rbegin()); }
	int getMin() { return *(s.begin()); }
};
 
int main() {
	Set integers;
	for (int i = 0; i < 10; i++) {
		int input;
		std::cout << "vec[" << i << "] : ";
		std::cin >> input;
		integers.insert(input);
	}
	std::cout << "-------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Max Number is : " << integers.getMax() << std::endl;
	std::cout << "Min Number is : " << integers.getMin() << std::endl;

	return 0;
}