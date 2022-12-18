#include <iostream>

class DrawAPI {			// DrawAPI Ŭ����
public: virtual void drawCircle(int radius, int x, int y)=0;	// ���� �����Լ� == �������̽�
};

class RedCircle : public DrawAPI {		// RedCircle Ŭ���� (DrawAPI ���)
public:
	void drawCircle(int radius, int x, int y) {			// drawCircle ��üȭ -> ���� �� ���� ���
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: "
			<< x << ", " << y << "]" << std::endl;
	}
};

class GreenCircle : public DrawAPI {	// GreenCircle Ŭ���� (DrawAPI ���)
public:
	void drawCircle(int radius, int x, int y) {			// drawCircle ��üȭ -> ��� �� ���� ���
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: "
			<< x << ", " << y << "]" << std::endl;
	}
};
 
class Shape {		// Shape Ŭ����
protected: 
	DrawAPI* drawAPI;				// DrawAPI Ŭ���� ������ ����
	Shape();						// �⺻ ������ ���
	Shape(DrawAPI* drawAPI) {		// ������ with DrawAPI
		this->drawAPI = drawAPI;	// ���� ���Ե� drawAPI�� ����
	}
public: virtual void draw()=0;		// ���� �����Լ� == �������̽�
};

class Circle : public Shape {		// Circle Ŭ���� (Shape ���)
private: int x, y, radius;			// x��ǥ, y��ǥ, ������
public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) :	// Circle ������
		x(x), y(y), radius(radius), Shape(drawAPI) {}		// �ش� ��ġ�� ���� ����

	void draw() { (*drawAPI).drawCircle(radius, x, y); }	// draw ��üȭ -> �ش� drawAPI�� �̵��Ͽ� drawCircle
};

int main() {
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle());		// ���� �� ����
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle());	// ��� �� ����

	(*redCircle).draw();												// ���� ���
	(*greenCircle).draw();												// ���� ���

	return 0;
};