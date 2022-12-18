#include <iostream>

template<typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}
template<> void swap<std::string> (std::string& a, std::string& b) {
	std::string tmp = a;
	a = b;
	b = tmp;
}
 
int main() {
	int a = 1;
	int b = 2;
	float c = 3.3;
	float d = 4.4;
	std::string e = "World";
	std::string f = "Hello";

	swap<int>(a, b);
	swap<float>(c, d);
	swap<>(e, f);

	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "e: " << e << ", f: " << f << std::endl;
	return 0;
}