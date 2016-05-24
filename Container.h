#pragma once

#include "Base.h"
#include "Pentagon.h"
#include "Triangle.h"
#include "LineSeg.h"

class Container	// double-linked circular list 
{
	struct Node {
		Base * ptr;
		Node * next;
		Node * prev;
		Node() { next = NULL; prev = NULL; }
	};

	Node * head;
	Node * tail;
	Node * curr;	// ������� ���������� ����������

	/*int containerId;
	static int containerCommonId;*/

public:
	Container();
	~Container();

	//int GetContainerId() const { return containerId; };
	//static int GetContainerCommonId() const { return containerCommonId;};

	void AddElement(Base &obj);	// ��������� ������� � ������
	Base * TakeElement();		// ���������� ��������� �� �������, ������ ��� �� ������
	Base * GetElementPtr();		// ���������� ��������� �� �������, �������� ��� � ������
	void ShowCurrElement(HDC hDC, HPEN hPen);	// ���������� �������
	void MoveItteratorForward();  // ���������� ������� ������� �� ��������� � ������	
	void MoveItteratorBackward(); // ���������� ������� ������� �� ���������� � ������
	void GetElementId() const { std::cout << "ID ������: " << (curr->ptr)->GetFigureId() << std::endl; }
};

