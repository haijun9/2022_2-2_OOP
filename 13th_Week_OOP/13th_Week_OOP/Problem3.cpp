#include <iostream>

class Shape { public: virtual void draw() = 0; }; // �������̽� Shape

class Rectangle : public Shape {	// Shape�� �̿��� Rectangle class
public: 
	void draw() {	// Rectangle���� ������ draw �Լ�
		std::cout << "Shape : Rectangle" << std::endl;
	}
};

class Circle : public Shape {		// Shape�� �̿��� Circle class
public:
	void draw() {	// Circle���� ������ draw �Լ�
		std::cout << "Shape : Circle" << std::endl;
	}
};

class ShapeDecorator : public Shape {	// Shape�� �̿��� ShapeDecorator class
protected: Shape* decoratedShape;		// Shape ������ �ּҸ� ���
public:
	ShapeDecorator(Shape* decoratedShape) {		// �����ڷ� decoratedShape�� �Է� �� ����
		this->decoratedShape = decoratedShape;
	}

	void draw() {	// decoratedShape�� �ش�Ǵ� Shape�� draw
		(*decoratedShape).draw();
	}
};
 
class RedShapeDecorator : public ShapeDecorator {	// ShapeDecorator�� �̿��� RedShapeDecorator
public :
	RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {} 
	// �����ڷ� �θ� Ŭ���� �ӿ� �Է� �� ����

	void draw() {		
		(*decoratedShape).draw();		// decoratedShape�� �ش�Ǵ� Shape�� draw
		setRedBorder(decoratedShape);	// ���� ������ ����
	}

private :
	void setRedBorder(Shape* decoratedShape) {		// ���� ������ �����ϴ� �Լ�
		std::cout << "Border Color : Red" << std::endl;
	}
};

int main() {
	Shape* circle = new Circle();									// ���� ���� �� circle
		
	Shape* redCircle = new RedShapeDecorator(new Circle());			// ���� ���� �� redcircle

	Shape* redRectangle = new RedShapeDecorator(new Rectangle());	// ���� ���� ���簢�� redRectangle
	std::cout << "Circle with normal border" << std::endl;
	circle->draw();													// circle�� draw

	std::cout << "\nCircle of red border" << std::endl;
	redCircle->draw();												// redCircle�� draw

	std::cout << "\nRectangle of red border" << std::endl;
	redRectangle->draw();											// redRectangle�� draw
}