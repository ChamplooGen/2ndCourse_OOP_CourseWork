//#include <iostream>
//#include <stdlib.h>
//#include <math.h>
//#include "Pentagon.h"
//#include "Triangle.h"
//#include "LineSeg.h"
//#include "Container.h"
//
//using namespace std;
//
//int Base::commonQuantity = 0;
//
//void main()
//{
//	setlocale(LC_ALL, "RUS");
//// Приготовления к рисованию
//	HWND hWND = GetConsoleWindow();
//	HDC hDC = GetDC(hWND);
//// Делаем несколько цветов для рисования
//	HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
//	HPEN hWhitePen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
//	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
//	HPEN hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
//	HPEN hBlackPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
//	HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
////
//	cout << " Начало программы 'Геометрические фигуры'." << endl;
//	cout << " Для перехода к следующему этапу теста нажмите любую клавишу." << endl;
//	cin.get();
//	system("cls");
//
//	Triangle f1(true, 350, 300, 100);
//	Pentagon f2(true, 350, 300, 100);
//	LineSeg f3(true, 350, 300, 100);
//
//	Container container;
//
//	container.AddElement(f1);
//	cout << " Добавление треугольника в контейнера." << endl;
//	container.ShowCurrElement(hDC, hRedPen);
//	cin.get();
//	system("cls");
//
//	container.ShowCurrElement(hDC, hBlackPen);
//	container.AddElement(f2);
//	cout << " Добавление пятиугольника в контейнер." << endl;
//	container.ShowCurrElement(hDC, hGreenPen);
//	cin.get();
//	system("cls");
//
//	container.ShowCurrElement(hDC, hBlackPen);
//	container.AddElement(f3);
//	cout << " Добавление отрезка в контейнер." << endl;
//	container.ShowCurrElement(hDC, hWhitePen);
//	cin.get();
//	system("cls");
//	container.ShowCurrElement(hDC, hBlackPen);
//
//	cout << " Первый элемент контейнера:" << endl;
//	container.MoveItteratorForward(); 
//	container.ShowCurrElement(hDC, hWhitePen);
//	cin.get();
//	container.ShowCurrElement(hDC, hBlackPen);
//	system("cls");
//	
//	cout << " Проверка изъятия элементов из контейнера." << endl;
//
//	cout << " Изъятие текущего объекта из контейнера и проверка" << endl;
//	cout << " его способностей." << endl;
//	cin.get();
//
//	Base *t;
//
//	t = container.TakeElement();
//	t->Draw(hDC, hRedPen);
//	cin.get();
//	t->Draw(hDC, hBlackPen);
//	t->Turn(30);
//	t->Draw(hDC, hBluePen);
//	cin.get();
//	t->Draw(hDC, hBlackPen);
//	t->StretchAtXTimes(2.0);
//	t->Draw(hDC, hGreenPen);
//	cin.get();
//	t->Draw(hDC, hBlackPen);
//	t->MoveAt(50, 100);
//	t->Draw(hDC, hWhitePen);
//	cin.get();
//	t->Draw(hDC, hBlackPen);
//	system("cls");
//
//	cout << " Id треугольника: " << t->GetFigureId()<<endl;
//	cout << " Последний выданный Id труегольников: " << Triangle::GetTriangleCommonId() << endl;
//	cout << " Количество треугольников: " << Triangle::GetTriangleQuantity() << endl;
//	cin.get();
//	system("cls");
//
//	cout << " Изъятие текущего объекта из контейнера и проверка" << endl;
//	cout << " его способностей." << endl;
//	cin.get();
//
//	t = container.TakeElement();
//	t->Draw(hDC, hRedPen);
//	cin.get();
//	t->Draw(hDC, hBlackPen);
//	t->Turn(30);
//	t->Draw(hDC, hBluePen);
//	cin.get();
//	t->Draw(hDC, hBlackPen);
//	t->StretchAtXTimes(2.0);
//	t->Draw(hDC, hGreenPen);
//	cin.get();
//	t->Draw(hDC, hBlackPen);
//	t->MoveAt(50, 100);
//	t->Draw(hDC, hWhitePen);
//	cin.get();
//	t->Draw(hDC, hBlackPen);
//	system("cls");
//
//	cout << " Id отрезка: " << t->GetFigureId() << endl;
//	cout << " Последний выданный Id отрезков: " << LineSeg::GetLineSegCommonId() << endl;
//	cout << " Количество отрезков: " << LineSeg::GetLineSegQuantity() << endl;
//	cin.get();
//	system("cls");
//
//	cout << " Изъятие текущего объекта из контейнера и проверка" << endl;
//	cout << " его способностей." << endl;
//	cin.get();
//
//	t = container.TakeElement();
//	t->Draw(hDC, hRedPen);
//	cin.get();
//	t->Draw(hDC, hBlackPen);
//	t->Turn(30);
//	t->Draw(hDC, hBluePen);
//	cin.get();
//	t->Draw(hDC, hBlackPen);
//	t->StretchAtXTimes(2.0);
//	t->Draw(hDC, hGreenPen);
//	cin.get();
//	t->Draw(hDC, hBlackPen);
//	t->MoveAt(50, 100);
//	t->Draw(hDC, hWhitePen);
//	cin.get();
//	t->Draw(hDC, hBlackPen);
//	system("cls");
//
//	cout << " Id прямоугольника: " << t->GetFigureId() << endl;
//	cout << " Последний выданный Id пятиугольников: " << Pentagon::GetPentagonCommonId() << endl;
//	cout << " Количество прямоугольников: " << Pentagon::GetPentagonQuantity() << endl;
//	cin.get();
//	system("cls");
//	
//	cout << " Общее количество фигур: " << Base::getCommonQuantity() << endl;
//	cin.get();
//	cout << " Попытка взять элемент из пустого контейнера: " << endl;
//	t = container.TakeElement();
//	cin.get();
//
//	cout << " End. Конец. \n";
//	cin.get();
//}
