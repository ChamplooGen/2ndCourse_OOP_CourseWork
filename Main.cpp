#include "ClientAndServer.h"
#include "Base.h"
#include <iostream>
using namespace std;

int Base::commonQuantity = 0;

void main()
{
	Server server1, server2;
	Client cl1, cl2, cl3;
	cout << " 'Client-server-client interaction'" << endl << endl;

	server1.AddNewClient(cl1);
	server1.AddNewClient(cl2);
	server2.AddNewClient(cl2);
	server2.AddNewClient(cl3);

	cout << " Server " << server1.GetServerID() << "\n";
	server1.ShowListOfClients(); cout << "\n\n";
	cout << " Server " << server2.GetServerID() << "\n";
	server2.ShowListOfClients(); cout << "\n";
	cin.get();
	system("cls");

	cout << " Client 1 is trying to send private message on server1" << endl << endl;
	cl1.SendPrivateMessage(&server1);
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
	system("cls");


	cout << " Client 2 is trying to send public message on server1." << endl << endl;
	cout << " Server " << server1.GetServerID() << "\n";
	server1.ShowListOfClients(); cout << "\n\n";
	cout << " Server " << server2.GetServerID() << "\n";
	server2.ShowListOfClients(); cout << "\n";
	cin.get();

	cl2.SendPublicMessage(&server1);
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
	cin.get();

	cout << " Message history of al existing clients." << endl << endl;
	cin.get();
	cout << " Client " << cl1.GetUserID() << "\n";
	cl1.ShowMessageHistory(); cout << "\n"; cin.get();

	cout << " Client " << cl2.GetUserID() << "\n";
	cl2.ShowMessageHistory(); cout << "\n"; cin.get();

	cout << " Client " << cl3.GetUserID() << "\n";
	cl3.ShowMessageHistory(); cout << "\n"; cin.get();

	cout << " Terminating the programm..." << endl;
	cin.get();
}