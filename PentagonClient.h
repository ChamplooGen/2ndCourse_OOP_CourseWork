#pragma once
#include "Pentagon.h"
#include "ClientAndServer.h"

class PentagonClient: public Pentagon, public Client
{
public:
	// Стандартный конструктор.
	PentagonClient(int newCenterX = 0, int newCenterY = 0, int newLen1 = 0, int newDeg1 = 0, int newLen2 = 0, int newDeg2 = 0,
		int newLen3 = 0, int newDeg3 = 0, int newLen4 = 0, int newDeg4 = 0, int newLen5 = 0, int newDeg5 = 0);
	// Правильный пятуигольник с расстоянием len от центра до каждой вершины
	PentagonClient(bool r, int newCenterX, int newCenterY, int len = 40);
	// Конструктор копирования
	PentagonClient(const PentagonClient &r);
	~PentagonClient();
};

