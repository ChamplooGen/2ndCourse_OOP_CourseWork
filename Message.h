#pragma once

#include <string>

class Message {
private:
	int _from,	// ID отправителя
		_to;	// ID получателя
	std::string _text;	// текст сообщения
public:
	Message();	// стандартный конструктор
	Message(int from, int to, std::string text); // к-р с параметрами
	Message(const Message &mess);	// конструктор копирования

	int GetFrom() const { return _from; };
	int GetTo() const { return _to; };
	void SetTo(int newTo) { _to = newTo; };
	void FillMessage(int from, bool all);
	std::string GetText() const { return _text; };
};
