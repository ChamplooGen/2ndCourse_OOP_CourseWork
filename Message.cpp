#include "Message.h"
#include <iostream>
using namespace std;

Message::Message() : _from(0), _to(0), _text("") { } // стандартный конструктор

Message::Message(int from, int to, std::string text) : // конструктор с параметрами
_from(from), _to(to), _text(text) { }

Message::Message(const Message &mess) // конструктор копирования
{
	_from = mess.GetFrom();
	_to = mess.GetTo();
	_text = mess.GetText();
}

void Message::FillMessage(int from, bool all)	// если all=1, сообщение отсылается всем
{
	cout << " Enter your message: \n ";
	getline(cin, _text);
	
	if (!all)
	{
		cout << " Enter reciever ID: ";
		cin >> _to;
	}

	_from = from;
}