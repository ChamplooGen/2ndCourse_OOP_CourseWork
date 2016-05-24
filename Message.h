#pragma once

#include <string>

class Message {
private:
	int _from,	// ID �����������
		_to;	// ID ����������
	std::string _text;	// ����� ���������
public:
	Message();	// ����������� �����������
	Message(int from, int to, std::string text); // �-� � �����������
	Message(const Message &mess);	// ����������� �����������

	int GetFrom() const { return _from; };
	int GetTo() const { return _to; };
	void SetTo(int newTo) { _to = newTo; };
	void FillMessage(int from, bool all);
	std::string GetText() const { return _text; };
};
