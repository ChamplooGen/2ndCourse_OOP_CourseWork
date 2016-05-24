#pragma once
#include "Base.h"

#define alphaPenta	72	// ���� ��� �������� ����������� �������������

class Pentagon : public Base {

  private:
	  int len1,
		  deg1;
	  int len2,
		  deg2;
	  int len3,
		  deg3;
	  int len4,
		  deg4;
	  int len5,
		  deg5;
	  int pentagonId;	// id �������������
	  static int pentagonCommonId;
	  static int pentagonQuantity;	// ���-�� ��������������

	  int GetPentagonId() const { return pentagonId; };
	
  public:
	  // ����������� �����������.
	  Pentagon(int newCenterX = 0, int newCenterY = 0, int newLen1 = 0, int newDeg1 = 0, int newLen2 = 0, int newDeg2 = 0, 
		  int newLen3 = 0, int newDeg3 = 0, int newLen4 = 0, int newDeg4 = 0, int newLen5 = 0, int newDeg5 = 0);
	  // ���������� ������������ � ����������� len �� ������ �� ������ �������
	  Pentagon(bool r, int newCenterX, int newCenterY, int len = 40);
	  // ����������� �����������
	  Pentagon(const Pentagon &r);
	  ~Pentagon();

	  void Draw(HDC &hDC, HPEN &hPEN) const;	// ������ ������ ��������� ������
	  void Turn(int Degree);			// ������������ ������ �� ��������� ���-�� ��������
	  void StretchAtXTimes(double X);

	  int GetFigureId() { return GetPentagonId(); };
	  static int GetPentagonCommonId() { return pentagonCommonId; };
	  static int GetPentagonQuantity() { return pentagonQuantity; };
};

