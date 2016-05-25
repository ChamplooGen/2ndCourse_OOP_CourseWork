#include "PentagonClient.h"


PentagonClient::PentagonClient(int newCenterX, int newCenterY, int newLen1, int newDeg1, int newLen2, int newDeg2,
	int newLen3, int newDeg3, int newLen4, int newDeg4, int newLen5, int newDeg5):
	Pentagon(newCenterX, newCenterY, newLen1, newDeg1, newLen2, newDeg2, newLen3, newDeg3, 
	newLen4, newDeg4, newLen5, newDeg5), Client()
{
	std::cout << " Пятиугольник-клиент: работа конструктора по умолчанию." << std::endl;
}

PentagonClient::PentagonClient(bool r, int newCenterX, int newCenterY, int len) :
Pentagon(r, newCenterX, newCenterY, len), Client()
{
	std::cout << " Пятиугольник-клиент: работа конструктора c параметрами." << std::endl;
}

PentagonClient::PentagonClient(const PentagonClient &r) : Pentagon(r), Client()
{
	std::cout << " Пятиугольник-клиент: работа конструктора копирования." << std::endl;
}

PentagonClient::~PentagonClient()
{
	std::cout << " Пятиугольник-клиент: работа деструктора." << std::endl;
}
