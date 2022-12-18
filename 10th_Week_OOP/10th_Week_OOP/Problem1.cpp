#include <iostream>
#include <string.h>

class Shape {		// Shape Ŭ����
public: virtual void draw()=0;	// ���� �����Լ� == �������̽�
};
 
class Rectangle : public Shape {	// Rectangle Ŭ���� (Shape ���)
public:
	void draw() {	// draw() ��üȭ -> Rectangle ���� ���
		std::cout << "Inside Rectangle::draw() method." << std::endl;
	}
};

class Square : public Shape {	// Square Ŭ���� (Shape ���)
public:
	void draw() {	// draw() ��üȭ -> Square ���� ���
		std::cout << "Inside Square::draw() method." << std::endl;
	}
};

class RoundedRectangle : public Shape {		// RoundedRectangle Ŭ���� (Shape ���)
public:
	void draw() {	// draw() ��üȭ -> RoundedRectangle ���� ���
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
};

class RoundedSquare : public Shape {	// RoundedSquare Ŭ���� (Shape ���)	
public:
	void draw() {	// draw() ��üȭ -> RoundeddSquare ���� ���
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};

class AbstractFactory {		// AbstractFactory Ŭ����
public: virtual Shape* getShape(const char* shapeType)=0; // ���� �����Լ� == �������̽�
};

class ShapeFactory : public AbstractFactory {	// ShapeFactory Ŭ���� (AbstractFactory ���)
public:
	Shape* getShape(const char* shapeType) {	// getShape ��üȭ
		if (strcmp("RECTANGLE", shapeType) == 0) return new Rectangle();	// �Է¿� ���� Rectangle ����
		else if (strcmp("SQUARE", shapeType) == 0) return new Square();	// �Է¿� ���� Square ����
		return NULL;	// �ƹ� �͵� �ƴ� ���
	}
};

class RoundedShapeFactory : public AbstractFactory {	// RoundedShapeFactory Ŭ���� (AbstractFactory ���)
public:
	Shape* getShape(const char* shapeType) {	// getShape ��üȭ
		if (strcmp("RECTANGLE", shapeType) == 0) return new RoundedRectangle();	// �Է¿� ���� RoundedRectangle ����
		else if (strcmp("SQUARE", shapeType) == 0) return new RoundedSquare();		// �Է¿� ���� RoundedSquare ����
		return NULL;	// �ƹ� �͵� �ƴ� ���
	}
};

class FactoryProducer {	// FactoryProducer Ŭ����
public:
	static AbstractFactory* getFactory(bool rounded) {	// getFactory �޼ҵ� -> rounded���� �ƴ��� ����
		if (rounded) return new RoundedShapeFactory();	// rounded�ϸ� RoundedShapeFactory ����
		else return new ShapeFactory();					// �ƴ� ��� ShapeFactory ����
	}
};

int main() {
	AbstractFactory* shapeFactory = FactoryProducer::getFactory(false);		// shapeFactory�� rounded���� ���� ���
	Shape* shape1 = (*shapeFactory).getShape("RECTANGLE");					// shape1�� Rectangle
	(*shape1).draw();														// ���� ���
	Shape* shape2 = (*shapeFactory).getShape("SQUARE");						// shape2�� Square
	(*shape2).draw();														// ���� ���
	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true);		// shapeFactory1���� rounded�� ���
	Shape* shape3 = (*shapeFactory1).getShape("RECTANGLE");					// shape3�� RoundedRectangle
	(*shape3).draw();														// ���� ���
	Shape* shape4 = (*shapeFactory1).getShape("SQUARE");					// shape4�� RoundedSquare
	(*shape4).draw();														// ���� ���

	return 0;
}