#pragma once
#include "LineSeg.h"
#include "ClientAndServer.h"

class LineSegClient: public LineSeg, public Client
{
public:
	// ����������� �����������.
	LineSegClient(int newCenterX = 0, int newCenterY = 0, int newDeg = 0, int newLen1 = 0, int newLen2 = 0);
	// ���������� ������� � ����������� len �� ������ �� ������� ����� �������
	LineSegClient(bool r, int newCenterX, int newCenterY, int len = 40);
	LineSegClient(const LineSegClient &r);
	~LineSegClient();
};

