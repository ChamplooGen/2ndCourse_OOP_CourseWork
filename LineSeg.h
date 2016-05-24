#pragma once
#include "Base.h"

class LineSeg : public Base {
private:
	int len1,
		len2;
	int deg;

	int lineSegId;	// id �������������
	static int lineSegCommonId;
	static int lineSegQuantity;	// ���-�� ��������������

	int GetLineSegId() const { return lineSegId; };

public:
	// ����������� �����������.
	LineSeg(int newCenterX = 0, int newCenterY = 0, int newDeg = 0, int newLen1 = 0, int newLen2 = 0);
	// ���������� ������� � ����������� len �� ������ �� ������� ����� �������
	LineSeg(bool r, int newCenterX, int newCenterY, int len = 40);
	LineSeg(const LineSeg &r);
	~LineSeg();

	void Draw(HDC &hDC, HPEN &hPEN) const;	// ������ ������ ��������� ������
	void Turn(int Degree);			// ������������ ������ �� ��������� ���-�� ��������
	void StretchAtXTimes(double X);

	int GetFigureId() { return GetLineSegId(); };
	static int GetLineSegCommonId() { return lineSegCommonId; };
	static int GetLineSegQuantity() { return lineSegQuantity; };

};

