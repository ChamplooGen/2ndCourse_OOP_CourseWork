// Базовый класс
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
	// координаты центра фигуры
	int centerX;
	int centerY;
	//
	static int commonQuantity;	// общее кол-во фигур базового класса

	// вспомогательные функции для расчета координат вершин относительно центра фигуры
	int makeX(int len, int deg) const;	// возвращает координату х
	int makeY(int len, int deg) const;	// возвращает координату у
	double rad(int x) const { return (Pi * x / 180); };		// переводит угол в градусах в радианы

public:

	static int getCommonQuantity() { return commonQuantity; };
	void SetNewCenter(int newCenterX, int newCenterY)	// Устанавливает новый центр фигуры
		{ centerX = newCenterX; centerY = newCenterY; };
	void MoveAt(int xDir = 0, int yDir = 0)		// перемещает объект на указанное кол-во пикселей по осям X и Y
		{ centerX += xDir; centerY += yDir; };
	// Виртуальные функции :
	virtual void Draw(HDC &hDC, HPEN &hPEN) const = 0;
	virtual void Turn(int Degree) = 0;
	virtual void StretchAtXTimes(double X) = 0;
	virtual int GetFigureId() = 0;
};

#endif // !IBASE_H

