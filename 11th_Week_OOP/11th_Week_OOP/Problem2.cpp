#include <iostream>
#include <set>

class Rect {
	int w, h;
public:
	Rect() : w(0), h(0) {}
	Rect(int w, int h) : w(w), h(h) {}
	int area() { return w * h; }
	void print() {
		std::cout << "(" << w << "," << h << "," << area() << ")" << std::endl;
	}
};
 
struct Sort {
	bool operator() (Rect a, Rect b) const {
		return a.area() < b.area();
	}
};

int main() {
	int count = 0;
	std::cout << "사각형의 개수: ";
	std::cin >> count;
	std::set<Rect, Sort> set;
	for (int i = 0; i < count; i++) {
		int input_w, input_h;
		std::cout << "사각형의 폭: ";
		std::cin >> input_w;
		std::cout << "사각형의 높이: ";
		std::cin >> input_h;
		set.insert(Rect(input_w, input_h));
	}
	for (auto rect : set) { rect.print(); }
	return 0;
}