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
	Node * curr;	// подобие иттератора контейнера

	/*int containerId;
	static int containerCommonId;*/

public:
	Container();
	~Container();

	//int GetContainerId() const { return containerId; };
	//static int GetContainerCommonId() const { return containerCommonId;};

	void AddElement(Base &obj);	// добавл€ет элемент в список
	Base * TakeElement();		// возвращает указатель на элемент, удал€€ его из списка
	Base * GetElementPtr();		// возвращает указатель на элемент, оставл€€ его в списке
	void ShowCurrElement(HDC hDC, HPEN hPen);	// показывает элемент
	void MoveItteratorForward();  // перемещает текущий элемент на следующий в списке	
	void MoveItteratorBackward(); // перемещает текущий элемент на предыдущий в списке
	void GetElementId() const { std::cout << "ID фигуры: " << (curr->ptr)->GetFigureId() << std::endl; }
};

