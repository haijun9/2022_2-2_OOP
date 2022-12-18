#include <iostream>
#include <string.h>

class Shape {		// Shape 클래스
public: virtual void draw()=0;	// 순수 가상함수 == 인터페이스
};
 
class Rectangle : public Shape {	// Rectangle 클래스 (Shape 상속)
public:
	void draw() {	// draw() 구체화 -> Rectangle 관련 출력
		std::cout << "Inside Rectangle::draw() method." << std::endl;
	}
};

class Square : public Shape {	// Square 클래스 (Shape 상속)
public:
	void draw() {	// draw() 구체화 -> Square 관련 출력
		std::cout << "Inside Square::draw() method." << std::endl;
	}
};

class RoundedRectangle : public Shape {		// RoundedRectangle 클래스 (Shape 상속)
public:
	void draw() {	// draw() 구체화 -> RoundedRectangle 관련 출력
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
};

class RoundedSquare : public Shape {	// RoundedSquare 클래스 (Shape 상속)	
public:
	void draw() {	// draw() 구체화 -> RoundeddSquare 관련 출력
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};

class AbstractFactory {		// AbstractFactory 클래스
public: virtual Shape* getShape(const char* shapeType)=0; // 순수 가상함수 == 인터페이스
};

class ShapeFactory : public AbstractFactory {	// ShapeFactory 클래스 (AbstractFactory 상속)
public:
	Shape* getShape(const char* shapeType) {	// getShape 구체화
		if (strcmp("RECTANGLE", shapeType) == 0) return new Rectangle();	// 입력에 따른 Rectangle 생성
		else if (strcmp("SQUARE", shapeType) == 0) return new Square();	// 입력에 따른 Square 생성
		return NULL;	// 아무 것도 아닌 경우
	}
};

class RoundedShapeFactory : public AbstractFactory {	// RoundedShapeFactory 클래스 (AbstractFactory 상속)
public:
	Shape* getShape(const char* shapeType) {	// getShape 구체화
		if (strcmp("RECTANGLE", shapeType) == 0) return new RoundedRectangle();	// 입력에 따른 RoundedRectangle 생성
		else if (strcmp("SQUARE", shapeType) == 0) return new RoundedSquare();		// 입력에 따른 RoundedSquare 생성
		return NULL;	// 아무 것도 아닌 경우
	}
};

class FactoryProducer {	// FactoryProducer 클래스
public:
	static AbstractFactory* getFactory(bool rounded) {	// getFactory 메소드 -> rounded인지 아닌지 구분
		if (rounded) return new RoundedShapeFactory();	// rounded하면 RoundedShapeFactory 생성
		else return new ShapeFactory();					// 아닌 경우 ShapeFactory 생성
	}
};

int main() {
	AbstractFactory* shapeFactory = FactoryProducer::getFactory(false);		// shapeFactory로 rounded하지 않은 경우
	Shape* shape1 = (*shapeFactory).getShape("RECTANGLE");					// shape1은 Rectangle
	(*shape1).draw();														// 내용 출력
	Shape* shape2 = (*shapeFactory).getShape("SQUARE");						// shape2는 Square
	(*shape2).draw();														// 내용 출력
	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true);		// shapeFactory1으로 rounded한 경우
	Shape* shape3 = (*shapeFactory1).getShape("RECTANGLE");					// shape3은 RoundedRectangle
	(*shape3).draw();														// 내용 출력
	Shape* shape4 = (*shapeFactory1).getShape("SQUARE");					// shape4는 RoundedSquare
	(*shape4).draw();														// 내용 출력

	return 0;
}