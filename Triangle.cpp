#include "Triangle.h"

int Triangle::triangleCommonId = 0;
int Triangle::triangleQuantity = 0;

Triangle::Triangle(int newCenterX, int newCenterY, int newLen1, int newDeg1, int newLen2, int newDeg2,
	int newLen3, int newDeg3) :
	len1(newLen1), deg1(newDeg1), len2(newLen2), deg2(newDeg2), len3(newLen3), deg3(newDeg3)
{
	centerX = newCenterX;
	centerY = newCenterY;

	commonQuantity++;
	triangleCommonId++;
	triangleId = triangleCommonId;
	triangleQuantity++;
	std::cout << " �����������: ������ ������������ �� ���������." << std::endl;
}

Triangle::Triangle(bool r, int newCenterX, int newCenterY, int len) :	// ���� r = true, �� ������� ������������ ������������
deg1(alphaTrian), deg2(2 * alphaTrian), deg3(3 * alphaTrian) // ����� �������� ���������� �����������
{
	if (r) {
		len1 = len2 = len3 = len;
	}
	else {
		len1 = rand() % 100 + 5; len2 = rand() % 100 + 5;
		len3 = rand() % 100 + 5;
	}
	centerX = newCenterX;
	centerY = newCenterY;

	commonQuantity++;
	triangleCommonId++;
	triangleId = triangleCommonId;
	triangleQuantity++;
	std::cout << " �����������: ������ ������������ c �����������." << std::endl;
}

Triangle::Triangle(const Triangle &r) :
len1(r.len1), deg1(r.deg1), len2(r.len2), deg2(r.deg2), len3(r.len3), deg3(r.deg3)
{
	centerX = r.centerX;
	centerY = r.centerY;

	commonQuantity++;
	triangleCommonId++;
	triangleId = triangleCommonId;
	triangleQuantity++;
	std::cout << " �����������: ������ ������������ �����������." << std::endl;
}

Triangle::~Triangle()
{
	commonQuantity--;
	triangleQuantity--;
	std::cout << " �����������: ������ �����������." << std::endl;
}

void Triangle::Turn(int Degree)
{
	deg1 += Degree;
	deg2 += Degree;
	deg3 += Degree;
}

void Triangle::StretchAtXTimes(double X)
{
	len1 *= X; len2 *= X;
	len3 *= X; 
}

void Triangle::Draw(HDC &hDC, HPEN &hPEN) const
{
	SelectObject(hDC, hPEN);	// �������� ���� ��� ���������

	MoveToEx(hDC, centerX, centerY, NULL);
	Ellipse(hDC, centerX - 2, centerY - 2, centerX + 2, centerY + 2); // �������� ����� ������

	MoveToEx(hDC, centerX + makeX(len1, deg1), centerY - makeY(len1, deg1), NULL);	// ����������� ����� �� ������ �����
	LineTo(hDC, centerX + makeX(len2, deg2), centerY - makeY(len2, deg2));
	LineTo(hDC, centerX + makeX(len3, deg3), centerY - makeY(len3, deg3));
	LineTo(hDC, centerX + makeX(len1, deg1), centerY - makeY(len1, deg1));
}