#pragma once
#include "LineSeg.h"
#include "ClientAndServer.h"

class LineSegClient: public LineSeg, public Client
{
public:
	// —тандартный конструктор.
	LineSegClient(int newCenterX = 0, int newCenterY = 0, int newDeg = 0, int newLen1 = 0, int newLen2 = 0);
	// ѕравильный отрезок с рассто€нием len от центра до каждого конца отрезка
	LineSegClient(bool r, int newCenterX, int newCenterY, int len = 40);
	LineSegClient(const LineSegClient &r);
	~LineSegClient();
};

