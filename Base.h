// ������� �����
#ifndef BASE_H
#define BASE_H
#include <iostream>

#ifndef WINDOWS_H
#define WINDOWS_H
#include <Windows.h> 
#endif

#define Pi	3.14159265358979323846

class Base {
protected:
	// ���������� ������ ������
	int centerX;
	int centerY;
	//
	static int commonQuantity;	// ����� ���-�� ����� �������� ������

	// ��������������� ������� ��� ������� ��������� ������ ������������ ������ ������
	int makeX(int len, int deg) const;	// ���������� ���������� �
	int makeY(int len, int deg) const;	// ���������� ���������� �
	double rad(int x) const { return (Pi * x / 180); };		// ��������� ���� � �������� � �������

public:

	static int getCommonQuantity() { return commonQuantity; };
	void SetNewCenter(int newCenterX, int newCenterY)	// ������������� ����� ����� ������
		{ centerX = newCenterX; centerY = newCenterY; };
	void MoveAt(int xDir = 0, int yDir = 0)		// ���������� ������ �� ��������� ���-�� �������� �� ���� X � Y
		{ centerX += xDir; centerY += yDir; };
	// ����������� ������� :
	virtual void Draw(HDC &hDC, HPEN &hPEN) const = 0;
	virtual void Turn(int Degree) = 0;
	virtual void StretchAtXTimes(double X) = 0;
	virtual int GetFigureId() = 0;
};

#endif // !IBASE_H

