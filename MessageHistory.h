#pragma once

#include "Message.h"

class MessageHistory{
private:

	struct Node
	{
		Node *next;
		Node *prev;
		Message *message;
		Node() { prev = next = NULL; message = NULL; }
	};

	Node *curr, // текущий элемент списка истории сообщений
		 *tail;	// хвост списка истории сообщений
	void MoveForward();
	void MoveBackward();
	Message * GetCurrMessage() const;
public:
	MessageHistory();
	~MessageHistory();
	void AddElement(Message &mess);
	void ShowHistory();
	void DeleteHistory();
};