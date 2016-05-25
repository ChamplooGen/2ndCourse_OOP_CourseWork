#include "LineSegClient.h"


LineSegClient::LineSegClient(int newCenterX, int newCenterY, int newDeg, int newLen1, int newLen2) :
LineSeg	(newCenterX, newCenterY, newDeg, newLen1, newLen2), Client()
{
	std::cout << " ќтрезок-клиент: работа конструктора по умолчанию. " << std::endl;
}

LineSegClient::LineSegClient(bool r, int newCenterX, int newCenterY, int len) :
LineSeg(r, newCenterX, newCenterY, len), Client()
{
	std::cout << " ќтрезок-клиент: работа конструктора c параметрами. " << std::endl;
}

LineSegClient::LineSegClient(const LineSegClient &r) : LineSeg(r), Client()
{
	std::cout << " ќтрезок-клиент: работа конструктора копировани€. " << std::endl;
}


LineSegClient::~LineSegClient()
{
	std::cout << " ќтрезок-клиент: работа деструктора. " << std::endl;
}
