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
//// ������������� � ���������
//	HWND hWND = GetConsoleWindow();
//	HDC hDC = GetDC(hWND);
//// ������ ��������� ������ ��� ���������
//	HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
//	HPEN hWhitePen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
//	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
//	HPEN hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
//	HPEN hBlackPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
//	HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
////
//	cout << " ������ ��������� '�������������� ������'." << endl;
//	cout << " ��� �������� � ���������� ����� ����� ������� ����� �������." << endl;
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
//	cout << " ���������� ������������ � ����������." << endl;
//	container.ShowCurrElement(hDC, hRedPen);
//	cin.get();
//	system("cls");
//
//	container.ShowCurrElement(hDC, hBlackPen);
//	container.AddElement(f2);
//	cout << " ���������� ������������� � ���������." << endl;
//	container.ShowCurrElement(hDC, hGreenPen);
//	cin.get();
//	system("cls");
//
//	container.ShowCurrElement(hDC, hBlackPen);
//	container.AddElement(f3);
//	cout << " ���������� ������� � ���������." << endl;
//	container.ShowCurrElement(hDC, hWhitePen);
//	cin.get();
//	system("cls");
//	container.ShowCurrElement(hDC, hBlackPen);
//
//	cout << " ������ ������� ����������:" << endl;
//	container.MoveItteratorForward(); 
//	container.ShowCurrElement(hDC, hWhitePen);
//	cin.get();
//	container.ShowCurrElement(hDC, hBlackPen);
//	system("cls");
//	
//	cout << " �������� ������� ��������� �� ����������." << endl;
//
//	cout << " ������� �������� ������� �� ���������� � ��������" << endl;
//	cout << " ��� ������������." << endl;
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
//	cout << " Id ������������: " << t->GetFigureId()<<endl;
//	cout << " ��������� �������� Id �������������: " << Triangle::GetTriangleCommonId() << endl;
//	cout << " ���������� �������������: " << Triangle::GetTriangleQuantity() << endl;
//	cin.get();
//	system("cls");
//
//	cout << " ������� �������� ������� �� ���������� � ��������" << endl;
//	cout << " ��� ������������." << endl;
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
//	cout << " Id �������: " << t->GetFigureId() << endl;
//	cout << " ��������� �������� Id ��������: " << LineSeg::GetLineSegCommonId() << endl;
//	cout << " ���������� ��������: " << LineSeg::GetLineSegQuantity() << endl;
//	cin.get();
//	system("cls");
//
//	cout << " ������� �������� ������� �� ���������� � ��������" << endl;
//	cout << " ��� ������������." << endl;
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
//	cout << " Id ��������������: " << t->GetFigureId() << endl;
//	cout << " ��������� �������� Id ��������������: " << Pentagon::GetPentagonCommonId() << endl;
//	cout << " ���������� ���������������: " << Pentagon::GetPentagonQuantity() << endl;
//	cin.get();
//	system("cls");
//	
//	cout << " ����� ���������� �����: " << Base::getCommonQuantity() << endl;
//	cin.get();
//	cout << " ������� ����� ������� �� ������� ����������: " << endl;
//	t = container.TakeElement();
//	cin.get();
//
//	cout << " End. �����. \n";
//	cin.get();
//}
