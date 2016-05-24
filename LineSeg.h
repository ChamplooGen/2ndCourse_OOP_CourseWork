#pragma once
#include "Base.h"

class LineSeg : public Base {
private:
	int len1,
		len2;
	int deg;

	int lineSegId;	// id пятиугольника
	static int lineSegCommonId;
	static int lineSegQuantity;	// кол-во пятиугольников

	int GetLineSegId() const { return lineSegId; };

public:
	// Стандартный конструктор.
	LineSeg(int newCenterX = 0, int newCenterY = 0, int newDeg = 0, int newLen1 = 0, int newLen2 = 0);
	// Правильный отрезок с расстоянием len от центра до каждого конца отрезка
	LineSeg(bool r, int newCenterX, int newCenterY, int len = 40);
	LineSeg(const LineSeg &r);
	~LineSeg();

	void Draw(HDC &hDC, HPEN &hPEN) const;	// рисует объект указанным цветом
	void Turn(int Degree);			// поворачивает объект на указанное кол-во градусов
	void StretchAtXTimes(double X);

	int GetFigureId() { return GetLineSegId(); };
	static int GetLineSegCommonId() { return lineSegCommonId; };
	static int GetLineSegQuantity() { return lineSegQuantity; };

};

