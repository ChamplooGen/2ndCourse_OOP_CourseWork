#include "MessageHistory.h"
#include <iostream>

MessageHistory::MessageHistory()
{
	curr = tail = NULL;
}

MessageHistory::~MessageHistory()
{
	DeleteHistory();
}

void MessageHistory::AddElement(Message &mess)
{
	if (tail == NULL)
	{
		tail = new Node();
		tail->next = tail->prev = NULL;				// ��������� ��� ����������
		tail->message = new Message(mess);
		curr = tail;
	}
	else
	{
		curr = tail;
		tail->next = new Node();
		tail = tail->next;
		tail->next = NULL;							// ��������� ��� ����������
		tail->prev = curr;
		curr->next = tail;
		tail->message = new Message(mess);
		curr = tail;
	}
}

void MessageHistory::MoveForward()
{
	if (curr!=NULL && curr->next != NULL)
		curr = curr->next;
	else std::cout << "\n Warning: next or current el-t is NULL. \n";
}

void MessageHistory::MoveBackward()
{
	if (curr != NULL && curr->prev != NULL)
		curr = curr->prev;
	else std::cout << "\n Warning: previous or current el-t is NULL. \n";
}

Message * MessageHistory::GetCurrMessage() const
{
	if (tail != NULL)
	return curr->message;
	else std::cout << " Warning: message history is empty \n";
}

void MessageHistory::ShowHistory()
{
	if (!tail)	// ���� ������� ��������� �����
	{
		std::cout << " Warning: message history is empty \n";
		return;
	};
	while (curr->prev != NULL)
		MoveBackward();
	std::cout << " Message history: \n";
	while (curr != tail)
	{
		std::cout << "-------------\n";
		std::cout << " Sender ID: " << GetCurrMessage()->GetFrom() << std::endl;
		std::cout << " Reciever ID: " << GetCurrMessage()->GetTo() << std::endl;
		std::cout << " Message text: \n '"<< GetCurrMessage()->GetText() << "'\n";
		MoveForward();
	};	// ������� ��������� �������
	std::cout << "-------------\n";
	std::cout << " Sender ID: " << GetCurrMessage()->GetFrom() << std::endl;
	std::cout << " Reciever ID: " << GetCurrMessage()->GetTo() << std::endl;
	std::cout << " Message text: \n '" << GetCurrMessage()->GetText() << "'\n";
	std::cout << "-------------#\n";
}

void MessageHistory::DeleteHistory()
{
	curr = tail;
	while (tail != NULL)
	{
		curr = curr->prev;
		tail->next = tail->prev = NULL;
		delete tail->message;
		delete tail;
		tail = curr;
	}
}