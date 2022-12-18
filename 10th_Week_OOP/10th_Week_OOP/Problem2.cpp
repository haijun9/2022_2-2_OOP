#include <iostream>

class DrawAPI {			// DrawAPI 클래스
public: virtual void drawCircle(int radius, int x, int y)=0;	// 순수 가상함수 == 인터페이스
};

class RedCircle : public DrawAPI {		// RedCircle 클래스 (DrawAPI 상속)
public:
	void drawCircle(int radius, int x, int y) {			// drawCircle 구체화 -> 빨간 원 관련 출력
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: "
			<< x << ", " << y << "]" << std::endl;
	}
};

class GreenCircle : public DrawAPI {	// GreenCircle 클래스 (DrawAPI 상속)
public:
	void drawCircle(int radius, int x, int y) {			// drawCircle 구체화 -> 녹색 원 관련 출력
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: "
			<< x << ", " << y << "]" << std::endl;
	}
};
 
class Shape {		// Shape 클래스
protected: 
	DrawAPI* drawAPI;				// DrawAPI 클래스 포인터 변수
	Shape();						// 기본 생성자 명시
	Shape(DrawAPI* drawAPI) {		// 생성자 with DrawAPI
		this->drawAPI = drawAPI;	// 현재 포함된 drawAPI에 저장
	}
public: virtual void draw()=0;		// 순수 가상함수 == 인터페이스
};

class Circle : public Shape {		// Circle 클래스 (Shape 상속)
private: int x, y, radius;			// x좌표, y좌표, 반지름
public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) :	// Circle 생성자
		x(x), y(y), radius(radius), Shape(drawAPI) {}		// 해당 위치에 각각 저장

	void draw() { (*drawAPI).drawCircle(radius, x, y); }	// draw 구체화 -> 해당 drawAPI로 이동하여 drawCircle
};

int main() {
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle());		// 빨간 원 생성
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle());	// 녹색 원 생성

	(*redCircle).draw();												// 내용 출력
	(*greenCircle).draw();												// 내용 출력

	return 0;
};