#include "Pentagon.h"

int Pentagon::pentagonCommonId = 0;
int Pentagon::pentagonQuantity = 0;

Pentagon::Pentagon(int newCenterX, int newCenterY, int newLen1, int newDeg1, int newLen2, int newDeg2,
	int newLen3, int newDeg3, int newLen4, int newDeg4, int newLen5, int newDeg5) :
	len1(newLen1), deg1(newDeg1), len2(newLen2), deg2(newDeg2), len3(newLen3), 
	deg3(newDeg3), len4(newLen4), deg4(newDeg4), len5(newLen5), deg5(newDeg5)
{
	centerX = newCenterX;
	centerY = newCenterY;

	commonQuantity++;
	pentagonCommonId++;
	pentagonId = pentagonCommonId;
	pentagonQuantity++;
	std::cout << " Пятиугольник: работа конструктора по умолчанию." << std::endl;
}

Pentagon::Pentagon(bool r, int newCenterX, int newCenterY, int len) :	// если r = true, то стороны пятиугольника произвольные
deg1(alphaPenta), deg2(2*alphaPenta), deg3(3*alphaPenta), deg4(4*alphaPenta), deg5(5*alphaPenta) // иначе строится правильный пятиугольник
{
	if (r) {
		len1 = len2 = len3 = len4 = len5 = len;
	}
	else {
		len1 = rand() % 100 + 5; len2 = rand() % 100 + 5;
		len3 = rand() % 100 + 5; len4 = rand() % 100 + 5;
		len5 = rand() % 100 + 5;
	}
	centerX = newCenterX;
	centerY = newCenterY;

	commonQuantity++;
	pentagonCommonId++;
	pentagonId = pentagonCommonId;
	pentagonQuantity++;
	std::cout << " Пятиугольник: работа конструктора c параметрами."<<std::endl;
}

Pentagon::Pentagon(const Pentagon &r) :
len1(r.len1), deg1(r.deg1), len2(r.len2), deg2(r.deg2), len3(r.len3), 
deg3(r.deg3), len4(r.len4), deg4(r.deg4), len5(r.len5), deg5(r.deg5)
{
	centerX = r.centerX;
	centerY = r.centerY;

	commonQuantity++;
	pentagonCommonId++;
	pentagonId = pentagonCommonId;
	pentagonQuantity++;
	std::cout << " Пятиугольник: работа конструктора копирования." << std::endl;
}

Pentagon::~Pentagon()
{
	commonQuantity--;
	pentagonQuantity--;
	std::cout << " Пятиугольник: работа деструктора." << std::endl;
}

void Pentagon::Turn(int Degree)
{
	deg1 += Degree;
	deg2 += Degree;
	deg3 += Degree;
	deg4 += Degree;
	deg5 += Degree;
}

void Pentagon::StretchAtXTimes(double X)
{
	len1 = int (len1 * X); len2 = int (len2 * X);
	len3 = int (len3 * X); len4 = int (len4 * X);
	len5 = int (len5 * X);
}

void Pentagon::Draw(HDC &hDC, HPEN &hPEN) const
{
	SelectObject(hDC, hPEN);	// выбираем цвет для рисования

	MoveToEx(hDC, centerX, centerY, NULL);
	Ellipse(hDC, centerX - 1, centerY - 1, centerX + 1, centerY + 1); // высветим центр фигуры

	MoveToEx(hDC, centerX + makeX(len1, deg1), centerY - makeY(len1, deg1), NULL);	// передвигаем кисть на первую точку
	LineTo(hDC, centerX + makeX(len2, deg2), centerY - makeY(len2, deg2));
	LineTo(hDC, centerX + makeX(len3, deg3), centerY - makeY(len3, deg3));
	LineTo(hDC, centerX + makeX(len4, deg4), centerY - makeY(len4, deg4));
	LineTo(hDC, centerX + makeX(len5, deg5), centerY - makeY(len5, deg5));
	LineTo(hDC, centerX + makeX(len1, deg1), centerY - makeY(len1, deg1));
}