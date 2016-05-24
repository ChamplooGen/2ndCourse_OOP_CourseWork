#pragma once
#include "Base.h"

#define alphaPenta	72	// угол для создания правильного пятиугольника

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
	  int pentagonId;	// id пятиугольника
	  static int pentagonCommonId;
	  static int pentagonQuantity;	// кол-во пятиугольников

	  int GetPentagonId() const { return pentagonId; };
	
  public:
	  // Стандартный конструктор.
	  Pentagon(int newCenterX = 0, int newCenterY = 0, int newLen1 = 0, int newDeg1 = 0, int newLen2 = 0, int newDeg2 = 0, 
		  int newLen3 = 0, int newDeg3 = 0, int newLen4 = 0, int newDeg4 = 0, int newLen5 = 0, int newDeg5 = 0);
	  // Правильный пятуигольник с расстоянием len от центра до каждой вершины
	  Pentagon(bool r, int newCenterX, int newCenterY, int len = 40);
	  // Конструктор копирования
	  Pentagon(const Pentagon &r);
	  ~Pentagon();

	  void Draw(HDC &hDC, HPEN &hPEN) const;	// рисует объект указанным цветом
	  void Turn(int Degree);			// поворачивает объект на указанное кол-во градусов
	  void StretchAtXTimes(double X);

	  int GetFigureId() { return GetPentagonId(); };
	  static int GetPentagonCommonId() { return pentagonCommonId; };
	  static int GetPentagonQuantity() { return pentagonQuantity; };
};

