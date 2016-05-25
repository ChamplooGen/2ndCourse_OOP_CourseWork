#include "TriangleClient.h"


TriangleClient::TriangleClient(int newCenterX, int newCenterY, int newLen1, int newDeg1, 
	int newLen2, int newDeg2, int newLen3, int newDeg3) :
	Triangle(newCenterX, newCenterY, newLen1, newDeg1, newLen2, newDeg2, newLen3, newDeg3), Client()
{
	std::cout << " �����������-������: ������ ������������ �� ���������." << std::endl;
}

TriangleClient::TriangleClient(bool r, int newCenterX, int newCenterY, int len) :
Triangle(r, newCenterX, newCenterY, len), Client()
{
	std::cout << " �����������-������: ������ ������������ c �����������." << std::endl;
}

TriangleClient::TriangleClient(const TriangleClient &r) :
Triangle(r), Client()
{
	std::cout << " �����������-������: ������ ������������ �����������." << std::endl;
}


TriangleClient::~TriangleClient()
{
	std::cout << " �����������-������: ������ �����������." << std::endl;
}
