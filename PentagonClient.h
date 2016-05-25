#pragma once
#include "Pentagon.h"
#include "ClientAndServer.h"

class PentagonClient: public Pentagon, public Client
{
public:
	// ����������� �����������.
	PentagonClient(int newCenterX = 0, int newCenterY = 0, int newLen1 = 0, int newDeg1 = 0, int newLen2 = 0, int newDeg2 = 0,
		int newLen3 = 0, int newDeg3 = 0, int newLen4 = 0, int newDeg4 = 0, int newLen5 = 0, int newDeg5 = 0);
	// ���������� ������������ � ����������� len �� ������ �� ������ �������
	PentagonClient(bool r, int newCenterX, int newCenterY, int len = 40);
	// ����������� �����������
	PentagonClient(const PentagonClient &r);
	~PentagonClient();
};

