#include "LineSeg.h"


int LineSeg::lineSegCommonId = 0;
int LineSeg::lineSegQuantity = 0;

LineSeg::LineSeg(int newCenterX, int newCenterY,int newDeg, int newLen1, int newLen2) :
len1(newLen1), deg(newDeg), len2(newLen2)
{
	centerX = newCenterX;
	centerY = newCenterY;

	commonQuantity++;
	lineSegCommonId++;
	lineSegId = lineSegCommonId;
	lineSegQuantity++;
	std::cout << " �������: ������ ������������ �� ���������. " << std::endl;
}

LineSeg::LineSeg(bool r, int newCenterX, int newCenterY, int len) :	// ���� r = true, �� ������� ������������� ������������
deg(0)																// ����� �������� ���������� ������������
{
	if (r) {
		len1 = len2 = len;
	}
	else {
		len1 = rand() % 100 + 1; len2 = rand() % 100 + 1;
	}
	centerX = newCenterX;
	centerY = newCenterY;

	commonQuantity++;
	lineSegCommonId++;
	lineSegId = lineSegCommonId;
	lineSegQuantity++;
	std::cout << " �������: ������ ������������ c �����������. " << std::endl;
}

LineSeg::LineSeg(const LineSeg &r) :
len1(r.len1), deg(r.deg), len2(r.len2)
{
	centerX = r.centerX;
	centerY = r.centerY;

	commonQuantity++;
	lineSegCommonId++;
	lineSegId = lineSegCommonId;
	lineSegQuantity++;
	std::cout << " �������: ������ ������������ �����������. " << std::endl;
}

LineSeg::~LineSeg()
{
	commonQuantity--;
	lineSegQuantity--;
	std::cout << " �������: ������ �����������. " << std::endl;
}

void LineSeg::Turn(int Degree)
{
	deg += Degree;
}

void LineSeg::StretchAtXTimes(double X)
{
	len1 *= X; len2 *= X;
}

void LineSeg::Draw(HDC &hDC, HPEN &hPEN) const
{
	SelectObject(hDC, hPEN);	// �������� ���� ��� ���������

	MoveToEx(hDC, centerX, centerY, NULL);
	Ellipse(hDC, centerX - 2, centerY - 2, centerX + 2, centerY + 2); // �������� ����� ������

	MoveToEx(hDC, centerX + makeX(len1, deg), centerY - makeY(len1, deg), NULL);	// ����������� ����� �� ������ �����
	LineTo(hDC, centerX + makeX(len2, deg + 180), centerY - makeY(len2, deg + 180));
}
