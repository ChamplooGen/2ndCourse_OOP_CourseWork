#pragma once
#include "Base.h"

#define alphaTrian	120	// ���� ��� �������� ����������� �������������

class Triangle : public Base {
  private:
	int len1,
		deg1;
	int len2,
		deg2;
	int len3,
		deg3;
	
	int triangleId;	// id �������������
	static int triangleCommonId;
	static int triangleQuantity;	// ���-�� ��������������

	int GetTriangleId() const { return triangleId; };

  public:
	// ����������� �����������.
	Triangle(int newCenterX = 0, int newCenterY = 0, int newLen1 = 0, int newDeg1 = 0, int newLen2 = 0, int newDeg2 = 0,
		int newLen3 = 0, int newDeg3 = 0);
	// ���������� ����������� � ����������� len �� ������ �� ������ �������
	Triangle(bool r, int newCenterX, int newCenterY, int len = 40); 
	// ����������� �����������
	Triangle(const Triangle &r);
	~Triangle();

	void Draw(HDC &hDC, HPEN &hPEN) const;	// ������ ������ ��������� ������
	void Turn(int Degree);			// ������������ ������ �� ��������� ���-�� ��������
	void StretchAtXTimes(double X);

	int GetFigureId() { return GetTriangleId(); };
	static int GetTriangleCommonId() { return triangleCommonId; };	
	static int GetTriangleQuantity() { return triangleQuantity; };

};

