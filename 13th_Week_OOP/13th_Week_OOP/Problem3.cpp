#include <iostream>

class Shape { public: virtual void draw() = 0; }; // 인터페이스 Shape

class Rectangle : public Shape {	// Shape를 이용한 Rectangle class
public: 
	void draw() {	// Rectangle에서 구현된 draw 함수
		std::cout << "Shape : Rectangle" << std::endl;
	}
};

class Circle : public Shape {		// Shape를 이용한 Circle class
public:
	void draw() {	// Circle에서 구현된 draw 함수
		std::cout << "Shape : Circle" << std::endl;
	}
};

class ShapeDecorator : public Shape {	// Shape를 이용한 ShapeDecorator class
protected: Shape* decoratedShape;		// Shape 변수의 주소를 기억
public:
	ShapeDecorator(Shape* decoratedShape) {		// 생성자로 decoratedShape에 입력 값 저장
		this->decoratedShape = decoratedShape;
	}

	void draw() {	// decoratedShape에 해당되는 Shape로 draw
		(*decoratedShape).draw();
	}
};
 
class RedShapeDecorator : public ShapeDecorator {	// ShapeDecorator를 이용한 RedShapeDecorator
public :
	RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {} 
	// 생성자로 부모 클래스 속에 입력 값 저장

	void draw() {		
		(*decoratedShape).draw();		// decoratedShape에 해당되는 Shape로 draw
		setRedBorder(decoratedShape);	// 붉은 선으로 설정
	}

private :
	void setRedBorder(Shape* decoratedShape) {		// 붉은 선으로 설정하는 함수
		std::cout << "Border Color : Red" << std::endl;
	}
};

int main() {
	Shape* circle = new Circle();									// 보통 선인 원 circle
		
	Shape* redCircle = new RedShapeDecorator(new Circle());			// 붉은 선인 원 redcircle

	Shape* redRectangle = new RedShapeDecorator(new Rectangle());	// 붉은 선인 직사각형 redRectangle
	std::cout << "Circle with normal border" << std::endl;
	circle->draw();													// circle의 draw

	std::cout << "\nCircle of red border" << std::endl;
	redCircle->draw();												// redCircle의 draw

	std::cout << "\nRectangle of red border" << std::endl;
	redRectangle->draw();											// redRectangle의 draw
}