#pragma once
#include "Triangle.h"
#include "ClientAndServer.h"

class TriangleClient: public Triangle, public Client
{
public:
	// Стандартный конструктор
	TriangleClient(int newCenterX = 0, int newCenterY = 0, int newLen1 = 0, int newDeg1 = 0, int newLen2 = 0, int newDeg2 = 0,
		int newLen3 = 0, int newDeg3 = 0);
	// Правильный треугольник с расстоянием len от центра до каждой вершины
	TriangleClient(bool r, int newCenterX, int newCenterY, int len = 40);
	// Конструктор копирования
	TriangleClient(const TriangleClient &r);
	~TriangleClient();
};

