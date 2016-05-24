#include "Container.h"

//int Container::containerCommonId = 0;

Container::Container()
{
	/*containerCommonId++;
	containerId = containerCommonId;*/
	std::cout << " ������ ������������ ����������\n";
	tail = curr = head = NULL;
}


Container::~Container()		// Check work-ability
{
	std::cout << " ������ ����������� ����������\n";
	curr = tail;
	if (!head) { std::cout << "\n ������ ��� ����.\n"; }
	else
	{
		tail->next = NULL;	// ��������� ����������� ������ ��� �������� ��� ��������
		head->prev = NULL;
		while (head->next != NULL)
		{
			tail = tail->prev;
			tail->next = NULL;

			curr->ptr = NULL;
			curr->next = NULL;
			curr->prev = NULL;
			delete curr;
			curr = tail;
		}
		curr->prev = NULL;
		curr->next = NULL;
		curr->ptr = NULL;
		delete curr;
		curr = tail = head = NULL;
	}
}

void Container::AddElement(Base &obj)	// ���������� ������ �������� � ������
{	
	if (head == NULL)	// ���� ������ ����, ������� ������ ������� ������
	{
		head = new Node;	// ������� ������� ������
		head->ptr = &obj;	// ��������� ��������� �� ������
		/*head->next = NULL;	// �������� ������ �� ��������� � ���������� ������� ������
		head->prev = NULL;*/
		head->next = head;
		head->prev = head;
		curr = tail = head;
	}
	else   // ������ �� ���� - ��������� � ����� �������
	{
		curr = tail;	// ������������ ������� ������� �� ����� ������
		tail->next = new Node;	// ������� �� ������� ����� �������
		tail = tail->next;		// ���������� ���� �����.
		tail->prev = curr;		// ��������� ����� ����� � ����������
		tail->next = head;		// ����������� ����� �� ������
		tail->ptr = &obj;		// ��������� � �������� ��������� �� ������
		curr = tail;
		head->prev = tail;
	}
}

Base * Container::TakeElement()
{
	if (!curr)	// ���� �������� ������� �������������� �������
	{
		std::cout << "\n Error: wrong try to get a NULL element.\n";
		return NULL;
	}

	Base * temp = curr->ptr;	// ��������� ����������� �������
	if (curr->next != curr)	// ���� � ������ ������� �� ���� �������
	{
		curr = curr->prev;
		curr->next = (curr->next)->next;
		if (head == NULL) head = curr->next;	// ���� ������� �������� �������
		if (tail == NULL) tail = curr;	// ���� ������� ��������� �������
	}
	else   // ���� � ������ ������� ���� �������
	{
		curr->ptr = NULL;
		curr->next = NULL;
		curr->prev = NULL;
		head = tail = curr = NULL;
	}; 
	return temp;
}

Base * Container::GetElementPtr()
{
	if (!curr)	// ���� �������� �������� ������ �� �������������� �������
	{
		std::cout << "\n Error: wrong try to get a NULL element.\n";
		return NULL;
	}
	else return curr->ptr;
}

void Container::ShowCurrElement(HDC hDC, HPEN hPen)
{
	if (!curr) { std::cout << "\n Error: wrong try to show NULL element.\n";}
	else
		(curr->ptr)->Draw(hDC, hPen);
}

void Container::MoveItteratorForward()	// ���������� ������� ������� �� ��������� � ������
{
	if (!curr->next || !curr) { std::cout << "\n Error: wrong try to move at NULL.\n"; }
	else curr = curr->next;
}

void Container::MoveItteratorBackward()	// ���������� ������� ������� �� ���������� � ������
{
	if (!curr->prev || !curr) { std::cout << "\n Error: wrong try to move at NULL.\n"; }
	else curr = curr->next;
}

