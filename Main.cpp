#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "ClientAndServer.h"
#include "TriangleClient.h"
#include "PentagonClient.h"
using namespace std;

int Base::commonQuantity = 0;

void main()
{
	setlocale(LC_ALL, "rus");
	// Приготовления к рисованию
	HWND hWND = GetConsoleWindow();
	HDC hDC = GetDC(hWND);
	// Делаем несколько цветов для рисования
	HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN hWhitePen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	HPEN hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	HPEN hBlackPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	//
//********************************************
	Server server1, server2;
	Client cl1, cl2, cl3;
	TriangleClient tr1(100, 100, 40, 0, 40, 120, 40, 240);	// клиент id #4

	tr1.Draw(hDC, hRedPen);
	cin.get();

	cout << " 'Client-server-client interaction'" << endl << endl;

	server1.AddNewClient(cl1);
	server1.AddNewClient(cl2); 
	server1.AddNewClient(tr1);

	server2.AddNewClient(cl2);
	server2.AddNewClient(cl3);

	cout << " Server " << server1.GetServerID() << "\n";
	server1.ShowListOfClients(); cout << "\n\n";
	cout << " Server " << server2.GetServerID() << "\n";
	server2.ShowListOfClients(); cout << "\n";
	cin.get();
	system("cls");

	cout << " Client 4 is trying to send private message on server1" << endl << endl;
	tr1.SendPrivateMessage(&server1);
	cin.get(); cin.get();
	system("cls");


	cout << " Message history of all existing clients." << endl << endl;
	cin.get();
	cout << " Client " << cl1.GetUserID() << "\n";
	cl1.ShowMessageHistory(); cout << "\n"; cin.get();

	cout << " Client " << cl2.GetUserID() << "\n";
	cl2.ShowMessageHistory(); cout << "\n"; cin.get();

	cout << " Client " << cl3.GetUserID() << "\n";
	cl3.ShowMessageHistory(); cout << "\n";
	cin.get();
	cout << " Client " << tr1.GetUserID() << "\n";
	tr1.ShowMessageHistory(); cout << "\n"; cin.get();
	system("cls");


	cout << " Client 4 is trying to send public message on server1." << endl << endl;
	cout << " Server " << server1.GetServerID() << "\n";
	server1.ShowListOfClients(); cout << "\n\n";
	cout << " Server " << server2.GetServerID() << "\n";
	server2.ShowListOfClients(); cout << "\n";
	cin.get();

	tr1.SendPublicMessage(&server1);
	cin.get();
	system("cls");

	cout << " Message history of al existing clients." << endl << endl;
	cin.get();
	cout << " Client " << cl1.GetUserID() << "\n";
	cl1.ShowMessageHistory(); cout << "\n"; cin.get();

	cout << " Client " << cl2.GetUserID() << "\n";
	cl2.ShowMessageHistory(); cout << "\n"; cin.get();

	cout << " Client " << cl3.GetUserID() << "\n";
	cl3.ShowMessageHistory(); cout << "\n"; cin.get();
	
	cout << " Client " << tr1.GetUserID() << "\n";
	tr1.ShowMessageHistory(); cout << "\n"; cin.get();
	system("cls");

	cout << " Client 3 is trying to send private message on server1" << endl << endl;
	cl3.SendPrivateMessage(&server1);
	cin.get(); cin.get();
	system("cls");

	cout << " Client 3 on server2: try to write message to client with ID 4." << endl << endl;
	cl3.SendPrivateMessage(&server2);
	cin.get(); cin.get();
	system("cls");

	cout << " Cleaning the history of all clients." << endl << endl;
	cl1.GetHistory()->DeleteHistory();
	cl2.GetHistory()->DeleteHistory();
	cl3.GetHistory()->DeleteHistory();
	tr1.GetHistory()->DeleteHistory();
	cin.get();

	cout << " Message history of al existing clients." << endl << endl;
	cin.get();
	cout << " Client " << cl1.GetUserID() << "\n";
	cl1.ShowMessageHistory(); cout << "\n"; cin.get();

	cout << " Client " << cl2.GetUserID() << "\n";
	cl2.ShowMessageHistory(); cout << "\n"; cin.get();

	cout << " Client " << cl3.GetUserID() << "\n";
	cl3.ShowMessageHistory(); cout << "\n"; cin.get();

	cout << " Client " << tr1.GetUserID() << "\n";
	tr1.ShowMessageHistory(); cout << "\n"; cin.get();
	system("cls");

	cout << " Terminating the programm..." << endl;
	cin.get();
}