#include "ClientAndServer.h"
#include <iostream>

int Server::commonID = 0;

Server::Server()
{
	commonID++;
	id = commonID;
	curr = tail = NULL;
}

Server::~Server()
{
	curr = tail;
	while (tail != NULL)
	{
		curr = curr->prev;
		tail->next = tail->prev = NULL;
		tail->client = NULL;
		delete tail;
		tail = curr;
	}
}

void Server::MoveForward()
{
	if (curr != NULL && curr->next != NULL)
		curr = curr->next;
	else std::cout << "\n Warning: next or current el-t is NULL. \n";
}

void Server::MoveBackward()
{
	if (curr != NULL && curr->prev != NULL)
		curr = curr->prev;
	else std::cout << "\n Warning: previous or current el-t is NULL. \n";
}

Client * Server::GetCurrClient() const
{
	if (tail != NULL)
		return curr->client;
	else std::cout << " Warning: the client list is empty \n";
}

void Server::AddNewClient(Client &newClient)
{
	if (tail == NULL)
	{
		tail = new Node();
		tail->client = &newClient;
		tail->next = tail->prev = NULL;				// ��������� ��� ����������
		curr = tail;
	}
	else
	{
		curr = tail;
		tail->next = new Node();
		tail = tail->next;
		tail->prev = curr;
		curr->next = tail;
		tail->client = &newClient;
		curr = tail;
	}
}

void Server::ShowListOfClients()
{
	while (curr->prev != NULL)
		MoveBackward();
	std::cout << "\n Client list of server #" << this->GetServerID()<<":\n";
	std::cout << "*****************\n";
	while (curr != tail)
	{
		std::cout << " Client id: " << GetCurrClient()->GetUserID() << std::endl;
		MoveForward();
	};	// ������� ��������� �������
	std::cout << " Client id: " << GetCurrClient()->GetUserID() << std::endl;
	std::cout << "*****************\n";
}

void Server::MessageForCurrClient(Message &message)
{
	if (!IsRegistered(message)) {	// ���� ����������� �� �� ���� �������
		std::cout << " You are not registered at this server. \n";
		return;
	}; curr->client->GetHistory()->AddElement(message); // ��������� ��������� � "���������" � �����������
	int id = message.GetTo();
	curr = tail;
	while (curr->prev != NULL && id != curr->client->GetUserID())	// ���� ������� ����������
		MoveBackward();
	if (id != curr->client->GetUserID()) // ������� �� ������
		std::cout << " Reciever is not found. \n";
	else
	{	// ��������� �����-� � ������� ���������
		curr->client->GetHistory()->AddElement(message);
		std::cout << " Your message is delivered to reciever. \n";
	};
	curr = tail;
}
void Server::MessageForEverybody(Message &message)
{
	curr = tail;
	while (curr != NULL)
	{	// ��������� ��������� � ������� ��������� ������� �������
		message.SetTo(curr->client->GetUserID());
		curr->client->GetHistory()->AddElement(message);
		curr = curr->prev;
	};
	std::cout << " Your message is delivered to everybody. \n";
	curr = tail;
}

bool Server::IsRegistered(Message &message)
{
	int id = message.GetFrom();
	curr = tail;
	while (curr->prev != NULL && id != curr->client->GetUserID())	// ���� ������� ����������
		MoveBackward();
	if (id != curr->client->GetUserID()) return 0;	// ����� ������������ �� ��������������� �� ������ �������
	else return 1;	// ����� ������������ ��������������� �� ������ �������
}