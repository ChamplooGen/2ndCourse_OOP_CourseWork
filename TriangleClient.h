#pragma once
#include "Triangle.h"
#include "ClientAndServer.h"

class TriangleClient: public Triangle, public Client
{
public:
	// ����������� �����������
	TriangleClient(int newCenterX = 0, int newCenterY = 0, int newLen1 = 0, int newDeg1 = 0, int newLen2 = 0, int newDeg2 = 0,
		int newLen3 = 0, int newDeg3 = 0);
	// ���������� ����������� � ����������� len �� ������ �� ������ �������
	TriangleClient(bool r, int newCenterX, int newCenterY, int len = 40);
	// ����������� �����������
	TriangleClient(const TriangleClient &r);
	~TriangleClient();
};

